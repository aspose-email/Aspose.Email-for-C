/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <Mapi/MapiObjectProperty.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadEmbeddedMessageFromAttachment()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"WithEmbeddedMsg.msg";
    
    // ExStart:ReadEmbeddedMessageFromAttachment
    auto message = MapiMessage::Load(fileName);
    if (message->get_Attachments()->idx_get(0)->get_ObjectData()->get_IsOutlookMessage())
    {
        auto getData = message->get_Attachments()->idx_get(0)->get_ObjectData()->ToMapiMessage();
    }
    // ExEnd:ReadEmbeddedMessageFromAttachment
}






