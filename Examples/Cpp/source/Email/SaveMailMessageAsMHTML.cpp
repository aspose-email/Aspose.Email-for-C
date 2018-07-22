/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <SaveOptions.h>
#include <MhtSaveOptions.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void SaveMailMessageAsMHTML()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:SaveMailMessageAsMHTML
    // Initialize and Load an existing EML file by specifying the MessageFormat
    System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir + u"Message.eml");
    
    eml->Save(dataDir + u"AnEmail_out.mthml", SaveOptions::get_DefaultMhtml());
    // ExEnd:SaveMailMessageAsMHTML
}






