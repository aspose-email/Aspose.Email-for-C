#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void SSLEnabledSMTPServer()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    System::String dstEmail = dataDir + u"test-load.eml";
    
    // ExStart:SSLEnabledSMTPServer
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com");
    
    // Set username, Password, Port No, and SecurityOptions
    client->set_Username(u"your.email@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(587);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
    // ExEnd:SSLEnabledSMTPServer
    
    // Declare message as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Use MailMessage properties like specify sender, recipient and message
    message->set_To(u"newcustomeronnet@gmail.com");
    message->set_From(u"newcustomeronnet@gmail.com");
    message->set_Subject(u"Test Email");
    message->set_Body(u"Hello World!");
    try
    {
        // Client will send this message
        client->Send(message);
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Email sent SSL successfully.");
}

