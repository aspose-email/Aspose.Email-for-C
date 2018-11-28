/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void ForwardEmail()
{
    // ExStart:ForwardEmail
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    
    //Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();
    
    // Specify your mailing host server, Username, Password, Port and SecurityOptions
    client->set_Host(u"mail.server.com");
    client->set_Username(u"username");
    client->set_Password(u"password");
    client->set_Port(587);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"Message.eml");
    client->Forward(u"Recipient1@domain.com", u"Recipient2@domain.com", message);
    // ExEnd:ForwardEmail
}

