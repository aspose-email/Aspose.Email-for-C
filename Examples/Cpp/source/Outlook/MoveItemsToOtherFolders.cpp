/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void MoveItemsToOtherFolders()
{
    // The path to the File directory.
    // ExStart:MoveItemsToOtherFolders
    System::String dataDir = GetDataDir_Outlook();
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + L"Outlook_1.pst");
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> inbox = personalStorage->GetPredefinedFolder(Aspose::Email::Outlook::Pst::StandardIpmFolder::Inbox);
        System::SharedPtr<FolderInfo> deleted = personalStorage->GetPredefinedFolder(Aspose::Email::Outlook::Pst::StandardIpmFolder::DeletedItems);
        System::SharedPtr<FolderInfo> subfolder = inbox->GetSubFolder(L"Inbox");
        
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
    // ExEnd:MoveItemsToOtherFolders
}







