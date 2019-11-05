#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/dictionary.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfigurationName.h>
#include <Clients/Exchange/WebService/UserConfiguration/UserConfiguration.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

void ReadUserConfiguration()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange 2010");

    try
    {
        // Get the User Configuration for Inbox folder
        System::SharedPtr<UserConfigurationName> userConfigName = System::MakeObject<UserConfigurationName>(u"inbox.config", client->get_MailboxInfo()->get_InboxUri());
        System::SharedPtr<UserConfiguration> userConfig = client->GetUserConfiguration(userConfigName);
    
        System::Console::WriteLine(System::String(u"Configuration Id: ") + userConfig->get_Id());
        System::Console::WriteLine(System::String(u"Configuration Name: ") + userConfig->get_UserConfigurationName()->get_Name());
        System::Console::WriteLine(u"Key value pairs:");
        for (auto o : System::IterateOver(userConfig->get_Dictionary()->get_Keys()))
        {
            System::String key = System::ObjectExt::Unbox<System::String>(o);
            System::Console::WriteLine(key + u": " + System::ObjectExt::ToString(userConfig->get_Dictionary()->idx_get(o)));
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

}

