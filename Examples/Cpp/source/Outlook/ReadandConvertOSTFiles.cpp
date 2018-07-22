/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FileFormat.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void ReadandConvertOSTFiles()
{
    //ExStart:ReadandConvertOSTFiles
    System::String dataDir = GetDataDir_Outlook();
    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorage.pst";
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
    // Get the Display Name of the file
    System::Console::WriteLine(System::String(u"Display Format: ") + System::ObjectExt::ToString(pst->get_Format()));
    //ExEnd:ReadandConvertOSTFiles
}

