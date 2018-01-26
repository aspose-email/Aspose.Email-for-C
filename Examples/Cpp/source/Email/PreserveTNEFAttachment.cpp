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
#include <system/enum_helpers.h>
#include <Mail/TemplateMerge/MailMessageSaveType.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/FileCompatibilityMode.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void PreserveTNEFAttachment()
{
    // ExStart:PreserveTNEFAttachment
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + L"PreserveOriginalBoundaries.eml");
    
    // Save as eml with preserved attachment
    System::SharedPtr<EmlSaveOptions> emlSaveOptions = [&]{ auto tmp_0 = System::MakeObject<EmlSaveOptions>(MailMessageSaveType::get_EmlFormat()); tmp_0->set_FileCompatibilityMode(Aspose::Email::Mail::FileCompatibilityMode::PreserveTnefAttachments); return tmp_0; }();
    mailMessage->Save(dataDir + L"PreserveTNEFAttachment_out.eml", emlSaveOptions);
    // ExEnd:PreserveTNEFAttachment
}






