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
#include <system/io/memory_stream.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReplaceEmbeddedMSGAttachmentContents()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"message3.msg";
    
    // ExStart:ReplaceEmbeddedMSGAttachmentContents
    auto message = MapiMessage::Load(fileName);
    auto memeoryStream = System::MakeObject<System::IO::MemoryStream>();
    message->get_Attachments()->idx_get(2)->Save(memeoryStream);
    auto getData = MapiMessage::Load(memeoryStream);
    message->get_Attachments()->Replace(1, u"new 1", getData);
    // ExEnd:ReplaceEmbeddedMSGAttachmentContents
    
    message->Save(dataDir + u"ReplaceEmbeddedMSGAttachmentContents_out.msg");
}






