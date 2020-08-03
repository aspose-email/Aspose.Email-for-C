#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <MailMessage.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void AccessCustomFolderUsingExchangeWebServiceClient()
{
    // Create instance of EWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    // Create ExchangeMailboxInfo, ExchangeMessageInfoCollection instance
    System::SharedPtr<ExchangeMailboxInfo> mailbox = client->GetMailboxInfo();
    System::SharedPtr<ExchangeMessageInfoCollection> messages;
    System::SharedPtr<ExchangeFolderInfo> subfolderInfo = System::MakeObject<ExchangeFolderInfo>();
    
    // Check if specified custom folder exisits and Get all the messages info from the target Uri
    client->FolderExists(mailbox->get_InboxUri(), u"TestInbox", subfolderInfo);
    
    //if custom folder exists
    if (subfolderInfo != nullptr)
    {
        messages = client->ListMessages(subfolderInfo->get_Uri());
        
        // Parse all the messages info collection
        for (auto info : System::IterateOver(messages))
        {
            System::String strMessageURI = info->get_UniqueUri();
            // now get the message details using FetchMessage()
            System::SharedPtr<MailMessage> msg = client->FetchMessage(strMessageURI);
            System::Console::WriteLine(System::String(u"Subject: ") + msg->get_Subject());
        }
    }
    else
    {
        System::Console::WriteLine(u"No folder with this name found.");
    }
}
