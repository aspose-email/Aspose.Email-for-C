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

void CreatingAndSavingOutlookMessages()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:CreatingAndSavingOutlookMessages
    // Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    
    // Set from, to, subject and body properties
    mailMsg->set_From(u"sender@domain.com");
    mailMsg->set_To(u"receiver@domain.com");
    mailMsg->set_Subject(u"This is test message");
    mailMsg->set_Body(u"This is test body");
    
    // Create an instance of the MapiMessage class and pass MailMessage as argument
    System::SharedPtr<MapiMessage> outlookMsg = MapiMessage::FromMailMessage(mailMsg);
    
    // Save the message (MSG) file
    System::String strMsgFile = u"CreatingAndSavingOutlookMessages_out.msg";
    outlookMsg->Save(dataDir + strMsgFile);
    // ExEnd:CreatingAndSavingOutlookMessages
}

