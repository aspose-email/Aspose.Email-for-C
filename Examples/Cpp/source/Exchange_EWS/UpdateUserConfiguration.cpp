#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/dictionary.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfigurationName.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfiguration.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

static System::SharedPtr<Aspose::Email::Clients::Exchange::WebService::IEWSClient> GetExchangeEWSClient()
{
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username@ASE305.onmicrosoft.com";
    const System::String password = u"password";
    System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    return client;
}

void UpdateUserConfiguration()
{
    try
    {
        
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient();
        System::Console::WriteLine(u"Connected to Exchange 2010");
        
        // Create the User Configuration for Inbox folder
        System::SharedPtr<UserConfigurationName> userConfigName = System::MakeObject<UserConfigurationName>(u"inbox.config", client->get_MailboxInfo()->get_InboxUri());
        System::SharedPtr<UserConfiguration> userConfig = client->GetUserConfiguration(userConfigName);
        userConfig->set_Id(nullptr);
        
        // Update User Configuration
        userConfig->get_Dictionary()->idx_set(System::ObjectExt::Box<System::String>(u"key1"), System::ObjectExt::Box<System::String>(u"new-value1"));
        client->UpdateUserConfiguration(userConfig);
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex.get_Message());
    }
    
}

