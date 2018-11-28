#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;


static System::SharedPtr<Aspose::Email::Clients::Smtp::SmtpClient> GetSmtpClient()
{
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"your.email@gmail.com", u"your.password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    return client;
}


void SettingHTMLBody()
{
    // Declare msg as MailMessage instance
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Use MailMessage properties like specify sender, recipient, message and HtmlBody
    msg->set_From(u"newcustomeronnet@gmail.com");
    msg->set_To(u"asposetest123@gmail.com");
    msg->set_Subject(u"Test subject");
    msg->set_HtmlBody(u"<html><body>This is the HTML body</body></html>");
    System::SharedPtr<SmtpClient> client = GetSmtpClient();
    try
    {
        // Client will send this message
        client->Send(msg);
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Email sent with HTML body.");
}


