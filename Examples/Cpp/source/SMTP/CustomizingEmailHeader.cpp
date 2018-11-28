#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Mime/HeaderCollection.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Mime;
using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void CustomizingEmailHeader()
{
    // ExStart:CustomizingEmailHeader
    // Create an instance MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Specify ReplyTo, From, To field
    message->get_ReplyToList()->Add(u"reply@reply.com");
    message->set_From(u"sender@sender.com");
    message->get_To()->Add(u"receiver1@receiver.com");
    
    // Adding CC and BCC Addresses
    message->get_CC()->Add(u"receiver2@receiver.com");
    message->get_Bcc()->Add(u"receiver3@receiver.com");
    
    // Specify Message subject, Specify Date and Specify XMailer
    message->set_Subject(u"test mail");
    message->set_Date(System::DateTime(2006, 3, 6));
    message->set_XMailer(u"Aspose.Email");
    message->get_Headers()->Add_(u"secret-header", u"mystery");
    
    // Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"your.email@gmail.com", u"your.password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
    try
    {
        // Client.Send will send this message
        client->Send(message);
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Email sent with customized headers.");
}

