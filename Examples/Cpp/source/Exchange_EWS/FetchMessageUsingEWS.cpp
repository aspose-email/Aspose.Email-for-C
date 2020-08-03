#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <MailMessage.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
void FetchMessageUsingEWS()
{
    try
    {
        // Create instance of ExchangeWebServiceClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Call ListMessages method to list messages info from Inbox
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        // Loop through the collection to get Message URI
        for (auto msgInfo : System::IterateOver(msgCollection))
        {
            System::String strMessageURI = msgInfo->get_UniqueUri();
            
            // Now get the message details using FetchMessage()
            System::SharedPtr<MailMessage> msg = client->FetchMessage(strMessageURI);
            
            for (auto att : System::IterateOver(msg->get_Attachments()))
            {
                System::Console::WriteLine(System::String(u"Attachment Name: ") + att->get_Name());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
