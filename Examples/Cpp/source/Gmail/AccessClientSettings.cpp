/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/keyvalue_pair.h>
#include <system/collections/ienumerator.h>
#include <system/collections/dictionary.h>
#include <cstdint>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email::Clients::Google;

void AccessClientSettings()
{
    try
    {
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);
        
        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                // Retrieve client settings
                System::SharedPtr<System::Collections::Generic::Dictionary<System::String, System::String>> settings = client->GetSettings();
                if (settings->get_Count() < 1)
                {
                    System::Console::WriteLine(u"No settings are available.");
                    return;
                }
                
                // Traverse the settings list
                
                {
                    auto pair_enumerator = (settings)->GetEnumerator();
                    decltype(pair_enumerator->get_Current()) pair;
                    while (pair_enumerator->MoveNext() && (pair = pair_enumerator->get_Current(), true))
                    {
                        // Get the setting value and test if settings are ok
                        System::String value = client->GetSetting(pair.get_Key());
                        if (pair.get_Value() == value)
                        {
                            System::Console::WriteLine(System::String(u"Key = ") + pair.get_Key() + u", Value = " + pair.get_Value());
                        }
                        else
                        {
                            System::Console::WriteLine(u"Settings could not be retrieved");
                        }
                    }
                }
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:AccessClientSettings
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
