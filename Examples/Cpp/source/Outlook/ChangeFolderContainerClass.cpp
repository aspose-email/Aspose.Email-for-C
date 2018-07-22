/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void ChangeFolderContainerClass()
{
    // ExStart:ChangeFolderContainerClass
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorage1.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
            folder->ChangeContainerClass(u"IPF.Note");
            personalStorage->Dispose();
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:ChangeFolderContainerClass
}

