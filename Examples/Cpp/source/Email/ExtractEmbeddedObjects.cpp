/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mail/MimeParts/LinkedResourceCollection.h>
#include <Mail/MimeParts/LinkedResource.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/Mime/ContentType.h>
#include <Mail/MailMessage/MailMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ExtractEmbeddedObjects()
{
    // ExStart:ExtractEmbeddedObjects
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance of MailMessage and load an email file
    System::SharedPtr<MailMessage> mailMsg = MailMessage::Load(dataDir + L"EmailWithAttandEmbedded.eml");
    
    // Extract Attachments from the message
    
    {
        auto attachment_enumerator = (mailMsg->get_Attachments())->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {
            // To display the the attachment file name
            System::Console::WriteLine(attachment->get_Name());
            
            // Save the attachment to disc
            attachment->Save(dataDir + attachment->get_Name());
            
            // You can also save the attachment to memory stream
            System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
            
            attachment->Save(ms);
        }
    }
    
    // Extract Inline images from the message
    
    {
        auto lr_enumerator = (mailMsg->get_LinkedResources())->GetEnumerator();
        decltype(lr_enumerator->get_Current()) lr;
        while (lr_enumerator->MoveNext() && (lr = lr_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(lr->get_ContentType()->get_Name());
            
            lr->Save(dataDir + lr->get_ContentType()->get_Name());
        }
    }
    // ExEnd:ExtractEmbeddedObjects
}






