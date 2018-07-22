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
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/enum_helpers.h>
#include <MailMessageSaveType.h>
#include <MailMessage.h>
#include <FileCompatibilityMode.h>
#include <EmlSaveOptions.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;

void AddNewTNEFAttachments()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:AddNewTNEFAttachments
    System::String fileName = u"tnefEml1.eml";
    System::String attachName = u"Untitled.jpg";
    System::String outFileName = u"test_out.eml";
    
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + fileName);
    mailMessage->get_Attachments()->Add(System::MakeObject<Attachment>(System::IO::File::OpenRead(dataDir + attachName), u"Untitled.jpg", u"image/jpg"));
    System::SharedPtr<EmlSaveOptions> eo = System::MakeObject<EmlSaveOptions>(MailMessageSaveType::get_EmlFormat());
    eo->set_FileCompatibilityMode(Aspose::Email::FileCompatibilityMode::PreserveTnefAttachments);
    mailMessage->Save(dataDir + outFileName, eo);
    // ExEnd:AddNewTNEFAttachments
}
