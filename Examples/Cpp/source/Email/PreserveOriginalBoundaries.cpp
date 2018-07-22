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
#include <MailMessageSaveType.h>
#include <MailMessage.h>
#include <EmlSaveOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void PreserveOriginalBoundaries()
{
    // ExStart:PreservOriginalBoundaries
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + u"Attachments.eml");
    
    // Save as eml with preserved original boundares
    System::SharedPtr<EmlSaveOptions> emlSaveOptions = [&]{ auto tmp_0 = System::MakeObject<EmlSaveOptions>(MailMessageSaveType::get_EmlFormat()); tmp_0->set_PreserveOriginalBoundaries(true); return tmp_0; }();
    mailMessage->Save(dataDir + u"PreserveOriginalBoundaries_out.eml", emlSaveOptions);
    // ExEnd:PreservOriginalBoundaries
}






