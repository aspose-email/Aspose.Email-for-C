#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Clients/Google/Calendar/Calendar.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Clients::Google;

void InsertFetchAndUpdateCalendar()
{
    try
    {
        // ExStart:InsertFetchAndUpdateCalendar
        // Get access token
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                // Insert, get and update calendar
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> calendar = System::MakeObject<Aspose::Email::Clients::Google::Calendar>(System::String(u"summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), nullptr, nullptr, u"America/Los_Angeles");
                
                // Insert calendar and Retrieve same calendar using id
                System::String id = client->CreateCalendar(calendar);
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> cal = client->FetchCalendar(id);
                
                //Match the retrieved calendar info with local calendar
                if ((calendar->get_Summary() == cal->get_Summary()) && (calendar->get_TimeZone() == cal->get_TimeZone()))
                {
                    System::Console::WriteLine(u"fetched calendar information matches");
                }
                else
                {
                    System::Console::WriteLine(u"fetched calendar information does not match");
                }
                
                // Change information in the fetched calendar and Update calendar
                cal->set_Description(System::String(u"Description - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                cal->set_Location(System::String(u"Location - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                client->UpdateCalendar(cal);
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        
        // ExEnd:InsertFetchAndUpdateCalendar
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
