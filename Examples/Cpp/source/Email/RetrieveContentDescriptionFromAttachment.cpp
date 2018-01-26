/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/Mime/HeaderCollection.h>
#include <Mail/MailMessage/MailMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void RetrieveContentDescriptionFromAttachment()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:RetrieveContentDescriptionFromAttachment
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + L"EmailWithAttandEmbedded.eml");
    
    System::String description = message->get_Attachments()->idx_get(0)->get_Headers()->idx_get(L"Content-Description");
    
    System::Console::WriteLine(description);
    // ExEnd:RetrieveContentDescriptionFromAttachment
}






