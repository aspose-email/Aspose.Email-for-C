/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MailConversionOptions.h>
#include <MailMessage.h>

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ConvertMSGToMIMEMessage()
{
    //ExStart:ConvertMSGToMIMEMessage
    System::SharedPtr<MapiMessage> msg = System::MakeObject<MapiMessage>(u"sender@test.com", u"recipient1@test.com; recipient2@test.com", u"Test Subject", u"This is a body of message.");
    auto options = System::MakeObject<MailConversionOptions>();
    options->set_ConvertAsTnef(true);
    System::SharedPtr<MailMessage> mail = msg->ToMailMessage(options);
    //ExEnd:ConvertMSGToMIMEMessage
}

