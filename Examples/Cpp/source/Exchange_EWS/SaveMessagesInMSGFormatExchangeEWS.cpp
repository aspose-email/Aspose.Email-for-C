#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>

#include "Examples.h"

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;

void SaveMessagesInMSGFormatExchangeEWS()
{
    System::String dataDir = GetDataDir_Exchange();
    
    try
    {
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Call ListMessages method to list messages info from Inbox
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        int32_t count = 0;
        // Loop through the collection to get Message URI
        for (auto msgInfo : System::IterateOver(msgCollection))
        {
            System::String strMessageURI = msgInfo->get_UniqueUri();
            
            // Now get the message details using FetchMessage() and Save message as Msg 
            System::SharedPtr<MailMessage> message = client->FetchMessage(strMessageURI);
            message->Save(dataDir + (count++) + u"_out.msg", SaveOptions::get_DefaultMsgUnicode());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
