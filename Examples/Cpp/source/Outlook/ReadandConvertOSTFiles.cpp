/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/FileFormat.h>

#include "Examples.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Outlook::Pst;


void ReadandConvertOSTFiles()
{
    //ExStart:ReadandConvertOSTFiles
    System::String dataDir = GetDataDir_Outlook();
    // Load the Outlook file
    System::String path = dataDir + L"PersonalStorage.pst";
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
    // Get the Display Name of the file
    System::Console::WriteLine(System::String(L"Display Format: ") + System::ObjectExt::ToString(pst->get_Format()));
    //ExEnd:ReadandConvertOSTFiles
}







