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
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <AlternateViewCollection.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email;

void SendingEmailWithAlternateText()
{
    // ExStart:SendingEmailWithAlternateText
    // Create an instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // From and To field
    message->set_From(u"sender@sender.com");
    message->get_To()->Add(u"receiver@receiver.com");
    
    System::SharedPtr<AlternateView> alternate;
    
    // Create an instance of AlternateView to view an email message using the content specified in the string
    alternate = AlternateView::CreateAlternateViewFromString(u"This is the alternate Text");
    
    // Add alternate text
    message->get_AlternateViews()->Add(alternate);
    
    // Create an instance of SmtpClient Class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();
    
    // Specify your mailing host server, user name, mail password and Port #
    client->set_Host(u"smtp.server.com");
    client->set_Username(u"Username");
    client->set_Password(u"Password");
    client->set_Port(25);
    try
    {
        // Client.Send will send this message
        client->Send(message);
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    // ExEnd:SendingEmailWithAlternateText
    
}

