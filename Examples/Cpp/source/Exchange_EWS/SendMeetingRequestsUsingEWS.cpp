#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Calendar/Recurrences/RecurrencePattern.h>
#include <Calendar/Recurrences/DailyRecurrencePattern.h>
#include <Calendar/Appointment.h>
#include <AlternateView.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Calendar::Recurrences;
void SendMeetingRequestsUsingEWS()
{
    try
    {
        // Create instance of IEWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Create the meeting request
        System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(u"meeting request", System::DateTime::get_Now().AddHours(1), System::DateTime::get_Now().AddHours(1.5), MailAddress::to_MailAddress(u"administrator@test.com"), MailAddressCollection::to_MailAddressCollection(u"bob@test.com"));
        app->set_Summary(u"meeting request summary");
        app->set_Description(u"description");
        
        
        System::SharedPtr<RecurrencePattern> pattern = System::MakeObject<Aspose::Email::Calendar::Recurrences::DailyRecurrencePattern>(System::DateTime::get_Now().AddDays(5));
        app->set_Recurrence(pattern);
        
        // Create the message and set the meeting request
        System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
        msg->set_From(MailAddress::to_MailAddress(u"administrator@test.com"));
        msg->set_To(MailAddressCollection::to_MailAddressCollection(u"bob@test.com"));
        msg->set_IsBodyHtml(true);
        msg->set_HtmlBody(u"<h3>HTML Heading</h3><p>Email Message detail</p>");
        msg->set_Subject(u"meeting request");
        msg->AddAlternateView(app->RequestApointment(0));
        
        // send the appointment
        client->Send(msg);
        System::Console::WriteLine(u"Appointment request sent");
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
