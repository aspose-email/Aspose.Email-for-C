/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void AddEmailAttachments()
{
    // ExStart:AddEmailAttachments
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance of MailMessage class
    System::SharedPtr<MailMessage> message = [&]{ auto tmp_0 = System::MakeObject<MailMessage>(); tmp_0->set_From(L"sender@sender.com"); return tmp_0; }();
    message->get_To()->Add(L"receiver@gmail.com");
    
    // Load an attachment
    System::SharedPtr<Attachment> attachment = System::MakeObject<Attachment>(dataDir + L"1.txt");
    
    // Add Multiple Attachment in instance of MailMessage class and Save message to disk
    message->get_Attachments()->Add(attachment);
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.jpg"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.doc"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.rar"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.pdf"));
    message->Save(dataDir + L"outputAttachments_out.msg", SaveOptions::get_DefaultMsgUnicode());
    // ExEnd:AddEmailAttachments
}






