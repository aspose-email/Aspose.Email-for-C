#if 0 // TEMPORARY OFF
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/idictionary.h>
#include <net/network_credential.h>
#include <net/icredentials.h>
#include <Clients/Exchange/Autodiscover/UserSettingName.h>
#include <Clients/Exchange/Autodiscover/GetUserSettingsResponse.h>
#include <Clients/Exchange/Autodiscover/AutodiscoverService.h>

using namespace Aspose::Email::Clients::Exchange;

void AutoDiscoverUsingEWS()
{
    System::String email = u"asposeemail.test3@aspose.com";
    System::String password = u"Aspose@2017";
    System::SharedPtr<AutodiscoverService> svc = System::MakeObject<AutodiscoverService>();
    svc->set_Credentials(System::MakeObject<System::Net::NetworkCredential>(email, password));
    
    System::SharedPtr<System::Collections::Generic::IDictionary<UserSettingName, System::SharedPtr<System::Object>>> userSettings = svc->GetUserSettings(email, System::MakeArray<UserSettingName>({UserSettingName::ExternalEwsUrl}))->get_Settings();
    System::String ewsUrl = System::ObjectExt::Unbox<System::String>(userSettings->idx_get(UserSettingName::ExternalEwsUrl));
    System::Console::WriteLine(System::String(u"Auto discovered EWS Url: ") + ewsUrl);
}
#endif
