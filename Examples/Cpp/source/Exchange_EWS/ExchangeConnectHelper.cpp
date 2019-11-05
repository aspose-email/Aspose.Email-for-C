#include "Examples.h"



#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

System::SharedPtr<Aspose::Email::Clients::Exchange::WebService::IEWSClient> GetExchangeEWSClient(ExchangeTestUser exchangeUser)
{
    const System::String mailboxUri = exchangeUser.MailboxUri;
    const System::String domain = exchangeUser.Domain;
    const System::String username = exchangeUser.Name;
    const System::String password = exchangeUser.Password;
    System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    System::SharedPtr<IEWSClient> client = EWSClient::GetEWSClient(mailboxUri, credentials);
    return client;
}
