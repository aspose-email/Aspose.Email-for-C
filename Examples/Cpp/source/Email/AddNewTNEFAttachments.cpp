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
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/enum_helpers.h>
#include <Mail/TemplateMerge/MailMessageSaveType.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/FileCompatibilityMode.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void AddNewTNEFAttachments()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:AddNewTNEFAttachments
    System::String fileName = L"tnefEml1.eml";
    System::String attachName = L"Untitled.jpg";
    System::String outFileName = L"test_out.eml";
    
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + fileName);
    mailMessage->get_Attachments()->Add(System::MakeObject<Attachment>(System::IO::File::OpenRead(dataDir + attachName), L"Untitled.jpg", L"image/jpg"));
    System::SharedPtr<EmlSaveOptions> eo = System::MakeObject<EmlSaveOptions>(MailMessageSaveType::get_EmlFormat());
    eo->set_FileCompatibilityMode(Aspose::Email::Mail::FileCompatibilityMode::PreserveTnefAttachments);
    mailMessage->Save(dataDir + outFileName, eo);
    // ExEnd:AddNewTNEFAttachments
}






