#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void MoveMessageFromOneFolderToAnotherusingEWS()
{
    // Create instance of IEWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo();
    
    // List all messages from Inbox folder
    System::Console::WriteLine(u"Listing all messages from Inbox....");
    System::SharedPtr<ExchangeMessageInfoCollection> msgInfoColl = client->ListMessages(mailboxInfo->get_InboxUri());
    for (auto msgInfo : System::IterateOver(msgInfoColl))
    {
        // Move message to "Processed" folder, after processing certain messages based on some criteria
        if (msgInfo->get_Subject() != nullptr && msgInfo->get_Subject().ToLower().Contains(u"process this message") == true)
        {
            client->MoveItem(mailboxInfo->get_DeletedItemsUri(), msgInfo->get_UniqueUri());
            // EWS
            System::Console::WriteLine(System::String(u"Message moved....") + msgInfo->get_Subject());
        }
        else { }
    }
}
