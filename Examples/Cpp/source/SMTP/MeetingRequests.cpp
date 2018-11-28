#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/date_time.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>
#include <Calendar/Appointment.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email;

static System::SharedPtr<Aspose::Email::Clients::Smtp::SmtpClient> GetSmtpClient()
{
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"your.email@gmail.com", u"your.password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    return client;
}


void MeetingRequests()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    System::String dstEmail = dataDir + u"outputAttachments.msg";
    
    // ExStart:SendingMeetingRequestsViaEmail
    // Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Set the sender, recipient, who will receive the meeting request. Basically, the recipient is the same as the meeting attendees
    msg->set_From(u"newcustomeronnet@gmail.com");
    msg->set_To(u"person1@domain.com, person2@domain.com, person3@domain.com, asposetest123@gmail.com");
    
    // Create Appointment instance
    System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(u"Room 112", System::DateTime(2015, 7, 17, 13, 0, 0), System::DateTime(2015, 7, 17, 14, 0, 0), msg->get_From(), msg->get_To());
    app->set_Summary(u"Release Meetting");
    app->set_Description(u"Discuss for the next release");
    
    // Add appointment to the message and Create an instance of SmtpClient class
    msg->AddAlternateView(app->RequestApointment());
    System::SharedPtr<SmtpClient> client = GetSmtpClient();
    
    try
    {
        // Client.Send will send this message
        client->Send(msg);
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    // ExEnd:SendingMeetingRequestsViaEmail
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Meeting request send successfully.");
}


