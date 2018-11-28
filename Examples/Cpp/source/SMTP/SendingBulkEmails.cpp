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
#include <MailMessageCollection.h>
#include <MailMessage.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email;

void SendingBulkEmails()
{
    // ExStart:SendingBulkEmails
    // Create SmtpClient as client and specify server, port, user name and password
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"mail.server.com", 25, u"Username", u"Password");
    
    // Create instances of MailMessage class and Specify To, From, Subject and Message
    System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg1@to.com", u"Subject1", u"message1, how are you?");
    System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg2@to.com", u"Subject2", u"message2, how are you?");
    System::SharedPtr<MailMessage> message3 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg3@to.com", u"Subject3", u"message3, how are you?");
    
    // Create an instance of MailMessageCollection class
    System::SharedPtr<MailMessageCollection> manyMsg = System::MakeObject<MailMessageCollection>();
    manyMsg->Add(message1);
    manyMsg->Add(message2);
    manyMsg->Add(message3);
    
    // Use client.BulkSend function to complete the bulk send task
    try
    {
        // Send Message using BulkSend method
        client->Send(manyMsg);
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    // ExEnd:SendingBulkEmails
}

