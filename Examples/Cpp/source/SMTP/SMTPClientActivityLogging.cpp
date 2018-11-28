/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email;

void SMTPClientActivityLogging()
{
    // ExStart:SMTPClientActivityLogging
    // Build message
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set email address for From and TO
    message->set_From(u"userFrom@gmail.com");
    message->set_To(u"userTo@gmail.com");
    
    // Set Subject and Body
    message->set_Subject(u"Appointment Request");
    message->set_Body(u"Test Body");
    
    // Initialize SmtpClient and Set valid user name and password, Port and SecurityOptions
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();
    client->set_Host(u"smtp.gmail.com");
    client->set_Username(u"userFrom");
    client->set_Password(u"***********");
    client->set_Port(587);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
    try
    {
        client->Send(message);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
    // ExEnd:SMTPClientActivityLogging
}

