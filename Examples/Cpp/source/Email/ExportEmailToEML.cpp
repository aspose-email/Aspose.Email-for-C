/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ExportEmailToEML()
{
    // ExStart:ExportEmailToEML
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + L"Message.eml");
    
    msg->Save(dataDir + L"ExporttoEml_out.eml", SaveOptions::get_DefaultEml());
    // ExEnd:ExportEmailToEML
    
}






