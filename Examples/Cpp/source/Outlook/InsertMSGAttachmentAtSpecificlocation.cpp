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

void InsertMSGAttachmentAtSpecificlocation()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"message3.msg";
    
    // ExStart:InsertMSGAttachmentAtSpecificlocation
    auto message = MapiMessage::FromFile(fileName);
    auto memoryStream = System::MakeObject<System::IO::MemoryStream>();
    message->get_Attachments()->idx_get(2)->Save(memoryStream);
    
    auto getData = MapiMessage::FromStream(memoryStream);
    message->get_Attachments()->Insert(1, u"new 11", getData);
    // ExEnd:InsertMSGAttachmentAtSpecificlocation
    
    message->Save(dataDir + u"AttachmentAtSpecificlocation_out.msg");
}






