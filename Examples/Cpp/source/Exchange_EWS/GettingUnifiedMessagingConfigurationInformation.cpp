#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/UnifiedMessaging/UnifiedMessagingConfiguration.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
void GettingUnifiedMessagingConfigurationInformation()
{
    const System::String mailboxUri = u"https://exchange.domain.com/ews/Exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username";
    const System::String password = u"password";
    System::SharedPtr<System::Net::NetworkCredential> credential = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::SharedPtr<UnifiedMessagingConfiguration> umConf = client->GetUMConfiguration();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
