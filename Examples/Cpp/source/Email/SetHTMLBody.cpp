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
#include <MailMessage.h>

using namespace Aspose::Email;

void SetHTMLBody()
{
    // ExStart:SetHTMLBody
    // Declare message as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Specify HtmlBody
    message->set_HtmlBody(u"<html><body>This is the HTML body</body></html>");
    // ExEnd:SetHTMLBody
}






