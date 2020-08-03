#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
void GetExchangeMessageInfoFromMessageURI()
{
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        System::SharedPtr<System::Collections::Generic::List<System::String>> ids = System::MakeObject<System::Collections::Generic::List<System::String>>();
        System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<MailMessage>>> messages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<MailMessage>>>();
        
        for (int32_t i = 0; i < 5; i++)
        {
            System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"user@domain.com", u"receiver@domain.com", System::String(u"EMAILNET-35033 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-35033 Messages saved from Sent Items folder doesn't contain 'To' field");
            messages->Add(message);
            System::String uri = client->AppendMessage(message);
            ids->Add(uri);
        }
        
        System::SharedPtr<ExchangeMessageInfoCollection> messageInfoCol = client->ListMessages(ids);
        
        for (auto messageInfo : System::IterateOver(messageInfoCol))
        {
            // Do something ...
            System::Console::WriteLine(messageInfo->get_UniqueUri());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
