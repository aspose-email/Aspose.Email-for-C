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
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void CreatingMSGFilesWithRTFBody()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:CreatingMSGFilesWithRTFBody
    // Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    
    // Set from, to, subject and body properties
    mailMsg->set_From(u"from@domain.com");
    mailMsg->set_To(u"to@domain.com");
    mailMsg->set_Subject(u"subject");
    mailMsg->set_HtmlBody(u"<h3>rtf example</h3><p>creating an <b><u>outlook message (msg)</u></b> file using Aspose.Email.</p>");
    
    System::SharedPtr<MapiMessage> outlookMsg = MapiMessage::FromMailMessage(mailMsg);
    outlookMsg->Save(dataDir + u"CreatingMSGFilesWithRTFBody_out.msg");
    // ExEnd:CreatingMSGFilesWithRTFBody
}

