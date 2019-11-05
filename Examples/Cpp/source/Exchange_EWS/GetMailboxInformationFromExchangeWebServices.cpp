#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void GetMailboxInformationFromExchangeWebServices()
{
    try
    {
        // Create instance of EWSClient class by giving credentials         
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Get mailbox size, exchange mailbox info, Mailbox and Inbox folder URI
        System::Console::WriteLine(System::String(u"Mailbox size: ") + client->GetMailboxSize() + u" bytes");
        System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo();
        System::Console::WriteLine(System::String(u"Mailbox URI: ") + mailboxInfo->get_MailboxUri());
        System::Console::WriteLine(System::String(u"Inbox folder URI: ") + mailboxInfo->get_InboxUri());
        System::Console::WriteLine(System::String(u"Sent Items URI: ") + mailboxInfo->get_SentItemsUri());
        System::Console::WriteLine(System::String(u"Drafts folder URI: ") + mailboxInfo->get_DraftsUri());
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
    }
    
    
}
