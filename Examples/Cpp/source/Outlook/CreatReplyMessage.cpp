/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <Tools/ResponseMessageBuilder/ReplyMessageBuilder.h>
#include <Tools/ResponseMessageBuilder/OriginalMessageAdditionMode.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Tools;

void CreatReplyMessage()
{
    // ExStart:CreatReplyMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> originalMsg = MapiMessage::Load(dataDir + u"message1.msg");
    System::SharedPtr<ReplyMessageBuilder> builder = System::MakeObject<ReplyMessageBuilder>();
    
    // Set ReplyMessageBuilder Properties
    builder->set_ReplyAll(true);
    builder->set_AdditionMode(Aspose::Email::Tools::OriginalMessageAdditionMode::Textpart);
    builder->set_ResponseText(u"<p><b>Dear Friend,</b></p> I want to do is introduce my co-author and co-teacher. <p><a href=\"www.google.com\">This is a first link</a></p><p><a href=\"www.google.com\">This is a second link</a></p>");
    
    System::SharedPtr<MapiMessage> replyMsg = builder->BuildResponse(originalMsg);
    replyMsg->Save(dataDir + u"reply_out.msg");
    // ExEnd:CreatReplyMessage
}

