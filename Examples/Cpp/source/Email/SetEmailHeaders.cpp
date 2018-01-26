/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <Mail/Mime/HeaderCollection.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void SetEmailHeaders()
{
    // ExStart:SetEmailHeaders
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance MailMessage class
    System::SharedPtr<MailMessage> mailMessage = System::MakeObject<MailMessage>();
    
    // Specify ReplyTo, From, To field, Cc and Bcc Addresses
    mailMessage->get_ReplyToList()->Add(L"reply@reply.com");
    mailMessage->set_From(L"sender@sender.com");
    mailMessage->get_To()->Add(L"receiver1@receiver.com");
    mailMessage->get_CC()->Add(L"receiver2@receiver.com");
    mailMessage->get_Bcc()->Add(L"receiver3@receiver.com");
    
    // Specify Date, Message subject, XMailer, Secret Header, Save message to disc
    mailMessage->set_Subject(L"test mail");
    mailMessage->set_Date(System::DateTime(2006, 3, 6));
    mailMessage->set_XMailer(L"Aspose.Email");
    mailMessage->get_Headers()->Add(L"secret-header", L"mystery");
    mailMessage->Save(dataDir + L"SetEmailHeaders_out.msg", SaveOptions::get_DefaultMsg());
    // ExEnd:SetEmailHeaders
}






