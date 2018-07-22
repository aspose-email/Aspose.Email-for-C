/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void MoveItemsToOtherFolders()
{
    // The path to the File directory.
    // ExStart:MoveItemsToOtherFolders
    System::String dataDir = GetDataDir_Outlook();
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"Outlook_1.pst");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> inbox = personalStorage->GetPredefinedFolder(Aspose::Email::Storage::Pst::StandardIpmFolder::Inbox);
            System::SharedPtr<FolderInfo> deleted = personalStorage->GetPredefinedFolder(Aspose::Email::Storage::Pst::StandardIpmFolder::DeletedItems);
            System::SharedPtr<FolderInfo> subfolder = inbox->GetSubFolder(u"Inbox");
            
            if (subfolder != nullptr)
            {
                // Move folder to the Deleted Items
                personalStorage->MoveItem(subfolder, deleted);
                
                // Move message to the Deleted Items
                System::SharedPtr<MessageInfoCollection> contents = subfolder->GetContents();
                personalStorage->MoveItem(contents->idx_get(0), deleted);
                
                // Move all inbox subfolders to the Deleted Items
                inbox->MoveSubfolders(deleted);
                
                // Move all subfolder contents to the Deleted Items
                subfolder->MoveContents(deleted);
            }
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:MoveItemsToOtherFolders
}

