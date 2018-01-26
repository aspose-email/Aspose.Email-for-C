/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void AddFilesToPST()
{
    // The path to the File directory.            
    System::String dataDir = GetDataDir_Outlook();
    
    System::String path = dataDir + L"Ps1_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    // ExStart:AddFilesToPST
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"Ps1_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->AddSubFolder(L"Files");
        
        // Add Document.doc file with the "IPM.Document" message class by default.
        folder->AddFile(dataDir + L"attachment_1.doc", nullptr);
    }
    // ExEnd:AddFilesToPST
}







