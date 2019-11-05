#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <MailMessage.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
void CopyingMessageToAnotherFolder()
{
    try
    {
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-34997 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-34997 Exchange: Copy a message and get reference to the new Copy item");
        System::String messageUri = client->AppendMessage(message);
        System::String newMessageUri = client->CopyItem(messageUri, client->get_MailboxInfo()->get_DeletedItemsUri());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
