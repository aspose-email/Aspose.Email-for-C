/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void CreateNewPSTFileAndAddingSubfolders()
{
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + u"CreateNewPSTFileAndAddingSubfolders_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    else { }
    
    // ExStart:CreateNewPSTFileAndAddingSubfolders            
    // Create new PST
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(path, Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
    
    // Add new folder "Test"
    personalStorage->get_RootFolder()->AddSubFolder(u"Inbox");
    // ExEnd:CreateNewPSTFileAndAddingSubfolders           
}

