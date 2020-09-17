/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <Tools/ResponseMessageBuilder/OriginalMessageAdditionMode.h>
#include <Tools/ResponseMessageBuilder/ForwardMessageBuilder.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Tools;

void CreateForwardMessage()
{
    // ExStart:CreatForwardMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> originalMsg = MapiMessage::FromFile(dataDir + u"message1.msg");
    System::SharedPtr<ForwardMessageBuilder> builder = System::MakeObject<ForwardMessageBuilder>();
    builder->set_AdditionMode(Aspose::Email::Tools::OriginalMessageAdditionMode::Textpart);
    System::SharedPtr<MapiMessage> forwardMsg = builder->BuildResponse(originalMsg);
    forwardMsg->Save(dataDir + u"forward_out.msg");
    // ExEnd:CreatForwardMessage
}

