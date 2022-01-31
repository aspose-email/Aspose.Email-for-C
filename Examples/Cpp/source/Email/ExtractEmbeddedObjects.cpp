/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mime/ContentType.h>
#include <MailMessage.h>
#include <LinkedResourceCollection.h>
#include <LinkedResource.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mime;

void ExtractEmbeddedObjects()
{
    // ExStart:ExtractEmbeddedObjects
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance of MailMessage and load an email file
    System::SharedPtr<MailMessage> mailMsg = MailMessage::Load(dataDir + u"EmailWithAttandEmbedded.eml");
    
    // Extract Attachments from the message
    
    {
        for (auto&& attachment : System::IterateOver(mailMsg->get_Attachments()))
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
        for (auto&& lr : System::IterateOver(mailMsg->get_LinkedResources()))
        {
            System::Console::WriteLine(lr->get_ContentType()->get_Name());
            
            lr->Save(dataDir + lr->get_ContentType()->get_Name());
        }
    }
    // ExEnd:ExtractEmbeddedObjects
}






