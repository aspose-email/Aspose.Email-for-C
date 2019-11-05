#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void AddingHeadersToEWSRequests()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    client->AddHeader(u"X-AnchorMailbox", u"username@domain.com");
    System::SharedPtr<ExchangeMessageInfoCollection> messageInfoCol = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
}
