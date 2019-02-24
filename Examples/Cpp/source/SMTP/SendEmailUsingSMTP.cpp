/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/diagnostics/trace.h>
#include <system/console.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void SendEmailUsingSMTP()
{
    // Declare msg as MailMessage instance
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();
    
    // Specify your mailing host server, Username, Password, Port # and Security option
    client->set_Host(u"mail.server.com");
    client->set_Username(u"username");
    client->set_Password(u"password");
    client->set_Port(587);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
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
    
}

