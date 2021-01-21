#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object_ext.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/list_ext.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/FreebusyResponse.h>
#include <Clients/Google/Calendar/FreebusyQuery.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Clients/Google/Calendar/Calendar.h>
#include <Calendar/Appointment.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Google;

void QueryingCalendar()
{
    try
    {
        // ExStart:QueryingCalendar
        // Get access token
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        // Get IGmailClient
        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_1({ client});
            // ------------------------------------------
            
            try
            {
                // Initialize calendar item
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> calendar1 = System::MakeObject<Aspose::Email::Clients::Google::Calendar>(System::String(u"summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), nullptr, nullptr, u"Europe/Kiev");
                
                // Insert calendar and get back id of newly inserted calendar and Fetch the same calendar using calendar id
                System::String id = client->CreateCalendar(calendar1);
                System::SharedPtr<Aspose::Email::Clients::Google::Calendar> cal1 = client->FetchCalendar(id);
                System::String calendarId1 = cal1->get_Id();
                
                {
                    auto __finally_guard_0 = ::System::MakeScopeGuard([=]()
                    {
                        // Delete the calendar
                        client->DeleteCalendar(cal1->get_Id());
                    });
                    
                    try
                    {
                        // Get list of appointments in newly inserted calendar. It should be zero
                        System::ArrayPtr<System::SharedPtr<Appointment>> appointments = client->ListAppointments(calendarId1);
                        if (appointments->get_Length() != 0)
                        {
                            System::Console::WriteLine(u"Wrong number of appointments");
                            return;
                        }
                        
                        // Create a new appointment and Calculate appointment start and finish time
                        System::DateTime startDate = System::DateTime::get_Now();
                        System::DateTime endDate = startDate.AddHours(1);
                        
                        // Create attendees list for appointment
                        System::SharedPtr<MailAddressCollection> attendees = System::MakeObject<MailAddressCollection>();
                        attendees->Add(u"user1@domain.com");
                        attendees->Add(u"user2@domain.com");
                        
                        // Create appointment
                        System::SharedPtr<Appointment> app1 = System::MakeObject<Appointment>(System::String(u"Location - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), startDate, endDate, MailAddress::to_MailAddress(u"user2@domain.com"), attendees);
                        app1->set_Summary(System::String(u"Summary - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                        app1->set_Description(System::String(u"Description - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
                        app1->set_StartTimeZone(u"Europe/Kiev");
                        app1->set_EndTimeZone(u"Europe/Kiev");
                        
                        // Insert the newly created appointment and get back the same in case of successful insertion
                        System::SharedPtr<Appointment> app2 = client->CreateAppointment(calendarId1, app1);
                        
                        // Create Freebusy query by setting min/max timeand time zone
                        System::SharedPtr<FreebusyQuery> query = System::MakeObject<FreebusyQuery>();
                        query->set_TimeMin(System::DateTime::get_Now().AddDays(-1));
                        query->set_TimeMax(System::DateTime::get_Now().AddDays(1));
                        query->set_TimeZone(u"Europe/Kiev");
                        
                        // Set calendar item to search and Get the reponse of query containing 
                        query->get_Items()->Add(cal1->get_Id());
                        System::SharedPtr<FreebusyResponse> resp = client->GetFreebusyInfo(query);
                        // Delete the appointment
                        client->DeleteAppointment(calendarId1, app2->get_UniqueId());
                    }
                    catch (...)
                    {
                        throw;
                    }
                }
            }
            catch(...)
            {
                __dispose_guard_1.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:QueryingCalendar
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
