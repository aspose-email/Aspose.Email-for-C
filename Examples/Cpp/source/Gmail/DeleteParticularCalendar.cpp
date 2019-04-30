#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email::Clients::Google;

void DeleteParticularCalendar()
{
    try
    {
        // ExStart:DeleteParticularCalendar
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
                // Access and delete calendar with summary starting from "Calendar summary - "
                System::String summary = u"Calendar summary - ";
                
                // Get calendars list
                System::ArrayPtr<System::SharedPtr<ExtendedCalendar>> lst0 = client->ListCalendars();
                
                
                {
                    for (System::SharedPtr<ExtendedCalendar> extCal : lst0)
                    {
                        // Delete selected calendars
                        if (extCal->get_Summary().StartsWith(summary))
                        {
                            client->DeleteCalendar(extCal->get_Id());
                        }
                    }
                    
                }
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:DeleteParticularCalendar
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
