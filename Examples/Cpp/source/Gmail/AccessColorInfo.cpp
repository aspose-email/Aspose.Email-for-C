#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/keyvalue_pair.h>
#include <system/collections/ienumerator.h>
#include <system/collections/dictionary.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ColorsInfo.h>
#include <Clients/Google/Calendar/Colors.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Clients::Google;

void AccessColorInfo()
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
                System::SharedPtr<ColorsInfo> colors = client->GetColors();
                System::SharedPtr<System::Collections::Generic::Dictionary<System::String, System::SharedPtr<Colors>>> palettes = colors->get_Calendar();
                
                // Traverse the settings list
                
                {
                    auto pair_enumerator = (palettes)->GetEnumerator();
                    decltype(pair_enumerator->get_Current()) pair;
                    while (pair_enumerator->MoveNext() && (pair = pair_enumerator->get_Current(), true))
                    {
                        System::Console::WriteLine(System::String(u"Key = ") + pair.get_Key() + u", Color = " + pair.get_Value());
                    }
                }
                System::Console::WriteLine(System::String(u"Update Date = ") + colors->get_Updated());
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:AccessColorInfo
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
}
