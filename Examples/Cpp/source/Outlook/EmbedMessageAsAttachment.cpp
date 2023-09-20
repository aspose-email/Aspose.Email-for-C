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
#include <Mapi/MapiAttachmentCollection.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void EmbedMessageAsAttachment()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:EmbedMessageAsAttachment
    System::SharedPtr<MapiMessage> message = System::MakeObject<MapiMessage>(u"from@test.com", u"to@test.com", u"Subj", u"This is a message body");
    System::SharedPtr<MapiMessage> attachMsg = MapiMessage::Load(dataDir + u"Message.msg");
    message->get_Attachments()->Add(u"Weekly report.msg", attachMsg);
    message->Save(dataDir + u"WithEmbeddedMsg_out.msg");
    // ExEnd:EmbedMessageAsAttachment
}

