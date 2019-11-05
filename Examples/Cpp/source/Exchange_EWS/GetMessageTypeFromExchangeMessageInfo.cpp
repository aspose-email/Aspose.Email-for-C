#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/MessageInfoType.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
void GetMessageTypeFromExchangeMessageInfo()
{
    const System::String mailboxUri = u"https://exchange/ews/exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username@ASE305.onmicrosoft.com";
    const System::String password = u"password";
    System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::SharedPtr<ExchangeMessageInfoCollection> list = client->ListMessages(client->get_MailboxInfo()->get_DeletedItemsUri());
    System::Console::WriteLine(System::ObjectExt::ToString(list->idx_get(0)->get_MessageInfoType()));
}
