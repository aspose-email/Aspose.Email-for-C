/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void ChangeFolderContainerClass()
{
    // ExStart:ChangeFolderContainerClass
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + L"PersonalStorage1.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->GetSubFolder(L"Inbox");
        folder->ChangeContainerClass(L"IPF.Note");
        personalStorage->Dispose();
    }
    // ExEnd:ChangeFolderContainerClass
}







