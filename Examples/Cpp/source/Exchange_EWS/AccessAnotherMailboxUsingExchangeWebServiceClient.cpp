#include "Examples.h"
#include <system/shared_ptr.h>
#include <system/console.h>

#include "Examples.h"
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>

using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;

void AccessAnotherMailboxUsingExchangeWebServiceClient()
{
    try
    {
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        // Get Exchange mailbox info of other email account
        System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo(u"otherUser@domain.com");
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex->get_Message());
    }
}
