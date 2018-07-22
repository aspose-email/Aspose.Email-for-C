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


void ReadingOSTFiles()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:ReadingOSTFiles
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"PersonalStorageFile.ost");
    
    // Get the format of the file
    System::Console::WriteLine(System::String(u"File Format of OST: ") + System::ObjectExt::ToString(personalStorage->get_Format()));
    // ExEnd:ReadingOSTFiles
}


