#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/dictionary.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfigurationName.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfiguration.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
using namespace Aspose::Email::Clients::Exchange::WebService;

void CreatUserConfigurations()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange 2010");
    
    // Create the User Configuration for Inbox folder
    System::SharedPtr<UserConfigurationName> userConfigName = System::MakeObject<UserConfigurationName>(u"inbox.config", client->get_MailboxInfo()->get_InboxUri());
    System::SharedPtr<UserConfiguration> userConfig = System::MakeObject<UserConfiguration>(userConfigName);
    userConfig->get_Dictionary()->Add(System::ObjectExt::Box<System::String>(u"key1"), System::ObjectExt::Box<System::String>(u"value1"));
    userConfig->get_Dictionary()->Add(System::ObjectExt::Box<System::String>(u"key2"), System::ObjectExt::Box<System::String>(u"value2"));
    userConfig->get_Dictionary()->Add(System::ObjectExt::Box<System::String>(u"key3"), System::ObjectExt::Box<System::String>(u"value3"));

    try 
    {
        client->CreateUserConfiguration(userConfig);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
}

