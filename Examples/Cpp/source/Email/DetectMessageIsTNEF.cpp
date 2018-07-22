/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/convert.h>
#include <system/console.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void DetectMessageIsTNEF()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:DetectMessageIsTNEF
    System::SharedPtr<MailMessage> mail = MailMessage::Load(dataDir + u"tnefEml1.eml");
    
    bool isTnef = mail->get_OriginalIsTnef();
    
    System::Console::WriteLine(u"Is input EML originally TNEF? {0}", System::ObjectExt::Box<System::String>(System::Convert::ToString(isTnef)));
    // ExEnd:DetectMessageIsTNEF
}






