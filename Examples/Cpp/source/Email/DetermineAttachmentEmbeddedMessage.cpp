/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <MailMessage.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;

void DetermineAttachmentEmbeddedMessage()
{
    // ExStart:DetermineAttachmentEmbeddedMessage
    System::String dataDir = GetDataDir_Email() + u"EmailWithAttandEmbedded.eml";
    
    System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir);
    
    if (eml->get_Attachments()->idx_get(0)->get_IsEmbeddedMessage())
    {
        System::Console::WriteLine(u"Attachment is an embedded message.");
    }
    else
    {
        System::Console::WriteLine(u"Attachment is not an embedded message.");
    }
    // ExEnd:DetermineAttachmentEmbeddedMessage
}






