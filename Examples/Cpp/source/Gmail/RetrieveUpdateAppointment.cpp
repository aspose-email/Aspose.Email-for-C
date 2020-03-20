#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/array.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Calendar/AppointmentFlags.h>
#include <Calendar/Appointment.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Google;

void RetrieveUpdateAppointment()
{
    try
    {
        // ExStart:RetrieveUpdateAppointment
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        // Get IGmailclient
        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                System::String calendarId = client->ListCalendars()->idx_get(0)->get_Id();
                System::String AppointmentUniqueId = client->ListAppointments(calendarId)->idx_get(0)->get_UniqueId();
                
                // Retrieve Appointment
                System::SharedPtr<Appointment> app3 = client->FetchAppointment(calendarId, AppointmentUniqueId);
                // Change the appointment information
                app3->set_Summary(System::String(u"New Summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                app3->set_Description(System::String(u"New Description - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                app3->set_Location(System::String(u"New Location - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                app3->set_Flags(Aspose::Email::Calendar::AppointmentFlags::AllDayEvent);
                app3->set_StartDate(System::DateTime::get_Now().AddHours(2));
                app3->set_EndDate(app3->get_StartDate().AddHours(1));
                app3->set_StartTimeZone(u"Europe/Kiev");
                app3->set_EndTimeZone(u"Europe/Kiev");
                // Update the appointment and get back updated appointment
                System::SharedPtr<Appointment> app4 = client->UpdateAppointment(calendarId, app3);
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:RetrieveUpdateAppointment
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
