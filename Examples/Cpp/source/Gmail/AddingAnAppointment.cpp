#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Clients/Google/Calendar/Calendar.h>
#include <Calendar/Appointment.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Google;

void AddingAnAppointment()
{
    try
    {
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
                // Create local calendar	
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> calendar1 = System::MakeObject<Aspose::Email::Clients::Google::Calendar>(System::String(u"summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), nullptr, nullptr, u"Europe/Kiev");
                
                // Insert calendar and get id of inserted calendar and Get back calendar using an id
                System::String id = client->CreateCalendar(calendar1);
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> cal1 = client->FetchCalendar(id);
                System::String calendarId1 = cal1->get_Id();
                
                try
                {
                    // Retrieve list of appointments from the first calendar
                    System::ArrayPtr<System::SharedPtr<Appointment>> appointments = client->ListAppointments(calendarId1);
                    if (appointments->get_Length() > 0)
                    {
                        System::Console::WriteLine(u"Wrong number of appointments");
                        return;
                    }
                    
                    // Get current time and Calculate time after an hour from now
                    System::DateTime startDate = System::DateTime::get_Now();
                    System::DateTime endDate = startDate.AddHours(1);
                    
                    // Initialize a mail address collection and set attendees mail address
                    System::SharedPtr<MailAddressCollection> attendees = System::MakeObject<MailAddressCollection>();
                    attendees->Add(u"User1.EMail@domain.com");
                    attendees->Add(u"User3.EMail@domain.com");
                    
                    // Create an appointment with above attendees
                    System::SharedPtr<Appointment> app1 = System::MakeObject<Appointment>(System::String(u"Location - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), startDate, endDate, MailAddress::to_MailAddress(User2.EMail), attendees);
                    
                    // Set appointment summary, description, start/end time zone
                    app1->set_Summary(System::String(u"Summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                    app1->set_Description(System::String(u"Description - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                    app1->set_StartTimeZone(u"Europe/Kiev");
                    app1->set_EndTimeZone(u"Europe/Kiev");
                    
                    // Insert appointment in the first calendar inserted above and get back inserted appointment
                    System::SharedPtr<Appointment> app2 = client->CreateAppointment(calendarId1, app1);
                    
                    // Retrieve appointment using unique id
                    System::SharedPtr<Appointment> app3 = client->FetchAppointment(calendarId1, app2->get_UniqueId());
                }
                catch (System::Exception& ex)
                {
                    System::Console::WriteLine(ex.get_Message());
                }
                
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:AddingAnAppointment
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
