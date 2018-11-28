#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/console.h>
#include <MailMessage.h>
#include <EmlLoadOptions.h>
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


void ImportEML()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    System::String dstEmail = dataDir + u"test.eml";
    
    // Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Import from EML format
    msg = MailMessage::Load(dstEmail, System::MakeObject<EmlLoadOptions>());
    
    // Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = GetSmtpClient();
    
    try
    {
        // Client.Send will send this message
        client->Send(msg);
        // Show Message if email sent successfully
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Email sent. " + dstEmail);
}


