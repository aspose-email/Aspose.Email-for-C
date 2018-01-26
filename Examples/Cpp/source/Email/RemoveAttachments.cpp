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
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void RemoveAttachments()
{
    // ExStart:RemoveAttachments
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmailRemoved = dataDir + L"RemoveAttachments.msg";
    
    // Create an instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    message->set_From(L"sender@sender.com");
    message->get_To()->Add(L"receiver@gmail.com");
    
    // Load an attachment
    System::SharedPtr<Attachment> attachment = System::MakeObject<Attachment>(dataDir + L"1.txt");
    
    // Add Multiple Attachment in instance of MailMessage class and Save message to disk
    message->get_Attachments()->Add(attachment);
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.jpg"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.doc"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.rar"));
    message->AddAttachment(System::MakeObject<Attachment>(dataDir + L"1.pdf"));
    
    // Remove attachment from your MailMessage and Save message to disk after removing a single attachment 
    message->get_Attachments()->Remove(attachment);
    message->Save(dstEmailRemoved, SaveOptions::get_DefaultMsgUnicode());
    
    // Create a loop to display the no. of attachments present in email message
    
    {
        auto getAttachment_enumerator = (message->get_Attachments())->GetEnumerator();
        decltype(getAttachment_enumerator->get_Current()) getAttachment;
        while (getAttachment_enumerator->MoveNext() && (getAttachment = getAttachment_enumerator->get_Current(), true))
        {
            // Save your attachments here and Display the the attachment file name
            getAttachment->Save(dataDir + L"/RemoveAttachments/" + L"attachment_out" + getAttachment->get_Name());
            System::Console::WriteLine(getAttachment->get_Name());
        }
    }
    // ExEnd:RemoveAttachments
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Attachments removed successfully from " + dstEmailRemoved);
}






