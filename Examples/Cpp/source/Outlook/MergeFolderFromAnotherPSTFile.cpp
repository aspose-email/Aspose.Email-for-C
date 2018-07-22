/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/ItemMovedEventArgs.h>
#include <Storage/Pst/FolderInfo.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

static int32_t totalAdded = 0;

static void destinationFolder_ItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::ItemMovedEventArgs> e)
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
            System::SharedPtr<PersonalStorage> destinationPst = PersonalStorage::FromFile(dataDir + u"destination.pst");
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_1({ destinationPst});
            // ------------------------------------------
            
            try{
                System::SharedPtr<PersonalStorage> sourcePst = PersonalStorage::FromFile(dataDir + u"source.pst");
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard<1> __dispose_guard_0({ sourcePst});
                // ------------------------------------------
                
                try
                {
                    System::SharedPtr<FolderInfo> destinationFolder = destinationPst->get_RootFolder()->AddSubFolder(u"FolderFromAnotherPst");
                    System::SharedPtr<FolderInfo> sourceFolder = sourcePst->GetPredefinedFolder(Aspose::Email::Storage::Pst::StandardIpmFolder::DeletedItems);
                    
                    // The events subscription is an optional step for the tracking process only.
                    destinationFolder->ItemMoved.connect(destinationFolder_ItemMoved);
                    
                    // Merges with the folder from another pst.
                    destinationFolder->MergeWith(sourceFolder);
                    System::Console::WriteLine(u"Total messages added: {0}", System::ObjectExt::Box<int32_t>(totalAdded));
                }
                catch(...)
                {
                    __dispose_guard_0.SetCurrentException(std::current_exception());
                }
            }
            catch(...)
            {
                __dispose_guard_1.SetCurrentException(std::current_exception());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message() + u"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:MergePSTFolders
}


