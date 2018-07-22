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
#include <system/date_time.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <Mime/HeaderCollection.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mime;

void SetEmailHeaders()
{
    // ExStart:SetEmailHeaders
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance MailMessage class
    System::SharedPtr<MailMessage> mailMessage = System::MakeObject<MailMessage>();
    
    // Specify ReplyTo, From, To field, Cc and Bcc Addresses
    mailMessage->get_ReplyToList()->Add(u"reply@reply.com");
    mailMessage->set_From(u"sender@sender.com");
    mailMessage->get_To()->Add(u"receiver1@receiver.com");
    mailMessage->get_CC()->Add(u"receiver2@receiver.com");
    mailMessage->get_Bcc()->Add(u"receiver3@receiver.com");
    
    // Specify Date, Message subject, XMailer, Secret Header, Save message to disc
    mailMessage->set_Subject(u"test mail");
    mailMessage->set_Date(System::DateTime(2006, 3, 6));
    mailMessage->set_XMailer(u"Aspose.Email");
    mailMessage->get_Headers()->Add(u"secret-header", u"mystery");
    mailMessage->Save(dataDir + u"SetEmailHeaders_out.msg", SaveOptions::get_DefaultMsg());
    // ExEnd:SetEmailHeaders
}






