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
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>

#include "Examples.h"

using namespace Aspose::Email;

using namespace Aspose::Email::Clients::Smtp;void SendEmailWithAlternateText()
{
    // ExStart:SendEmailWithAlternateText
    //Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set From field, To field and Plain text body
    message->set_From(u"sender@sender.com");
    message->get_To()->Add(u"receiver@receiver.com");
    message->set_Body(u"This is Plain Text Body");
    
    // Create an instance of the SmtpClient class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();
    
    // And Specify your mailing host server, Username, Password and Port
    client->set_Host(u"smtp.server.com");
    client->set_Username(u"Username");
    client->set_Password(u"Password");
    client->set_Port(25);
    
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
    
    
    System::Console::WriteLine(u"Press enter to quit");
    System::Console::Read();
}

