/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <Mapi/MapiNote.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/IMapiMessageItem.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadMapiNote()
{
    // ExStart:ReadMapiNote
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiMessage> note = MapiMessage::FromFile(dataDir + u"MapiNote.msg");
    System::SharedPtr<MapiNote> note2 = System::DynamicCast<Aspose::Email::Mapi::MapiNote>(note->ToMapiMessageItem());
    // ExEnd:ReadMapiNote
}

