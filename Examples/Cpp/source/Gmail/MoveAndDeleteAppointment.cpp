#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Calendar/Appointment.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Google;

void MoveAndDeleteAppointment()
{
    try
    {
        // ExStart:MoveAndDeleteAppointment
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        // Get IGmailclient
        {
            System::SharedPtr<IGmailClient> client = Aspose::Email::Clients::Google::GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                System::String SourceCalendarId = client->ListCalendars()->idx_get(0)->get_Id();
                System::String DestinationCalendarId = client->ListCalendars()->idx_get(1)->get_Id();
                System::String TargetAppUniqueId = client->ListAppointments(SourceCalendarId)->idx_get(0)->get_UniqueId();
                
                // Retrieve the list of appointments in the destination calendar before moving the appointment
                System::ArrayPtr<System::SharedPtr<Appointment>> appointments = client->ListAppointments(DestinationCalendarId);
                System::Console::WriteLine(System::String(u"Before moving count = ") + appointments->get_Length());
                System::SharedPtr<Appointment> Movedapp = client->MoveAppointment(SourceCalendarId, DestinationCalendarId, TargetAppUniqueId);
                
                // Retrieve the list of appointments in the destination calendar after moving the appointment
                appointments = client->ListAppointments(DestinationCalendarId);
                System::Console::WriteLine(System::String(u"After moving count = ") + appointments->get_Length());
                
                // Delete particular appointment from a calendar using unique id
                client->DeleteAppointment(DestinationCalendarId, Movedapp->get_UniqueId());
                
                // Retrieve the list of appointments. It should be one less than the earlier appointments in the destination calendar
                appointments = client->ListAppointments(DestinationCalendarId);
                System::Console::WriteLine(System::String(u"After deleting count = ") + appointments->get_Length());
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        
        // ExEnd:MoveAndDeleteAppointment
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
