#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfigurationName.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
void DeleteUserConfiguration()
{
    const System::String mailboxUri = u"https://exchnage/ews/exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username@ASE305.onmicrosoft.com";
    const System::String password = u"password";
    
    System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange 2010");
    
    // Delete User Configuration
    System::SharedPtr<UserConfigurationName> userConfigName = System::MakeObject<UserConfigurationName>(u"inbox.config", client->get_MailboxInfo()->get_InboxUri());
    try 
    {
        client->DeleteUserConfiguration(userConfigName);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

}
