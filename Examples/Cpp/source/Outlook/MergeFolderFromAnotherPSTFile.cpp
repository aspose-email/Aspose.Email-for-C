/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/ItemMovedEventArgs.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


int32_t totalAdded = 0;

void destinationFolder_ItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e)
{
    totalAdded++;
}

void MergeFolderFromAnotherPSTFile()
{
    // The path to the File directory.
    // ExStart:MergePSTFolders
    System::String dataDir = GetDataDir_Outlook();
    try
    {
        {
            System::SharedPtr<PersonalStorage> destinationPst = PersonalStorage::FromFile(dataDir + L"destination.pst");
            
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard __dispose_guard_0{ destinationPst, ASPOSE_CURRENT_FUNCTION_LINE };
            // ------------------------------------------
            {
                System::SharedPtr<PersonalStorage> sourcePst = PersonalStorage::FromFile(dataDir + L"source.pst");
                
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard __dispose_guard_1{ sourcePst, ASPOSE_CURRENT_FUNCTION_LINE };
                // ------------------------------------------
                System::SharedPtr<FolderInfo> destinationFolder = destinationPst->get_RootFolder()->AddSubFolder(L"FolderFromAnotherPst");
                System::SharedPtr<FolderInfo> sourceFolder = sourcePst->GetPredefinedFolder(Aspose::Email::Outlook::Pst::StandardIpmFolder::DeletedItems);
                
                // The events subscription is an optional step for the tracking process only.
                destinationFolder->ItemMoved.connect(destinationFolder_ItemMoved);
                
                // Merges with the folder from another pst.
                destinationFolder->MergeWith(sourceFolder);
                System::Console::WriteLine(L"Total messages added: {0}", System::ObjectExt::Box<int32_t>(totalAdded));
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message() + L"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:MergePSTFolders
}








