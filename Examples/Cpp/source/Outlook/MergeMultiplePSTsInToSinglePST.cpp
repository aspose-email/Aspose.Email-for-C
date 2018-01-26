#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/StorageProcessedEventArgs.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/ItemMovedEventArgs.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


static int32_t totalAdded = 0;
static System::String currentFolder;
static int32_t messageCount = 0;

void PstMerge_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::StorageProcessedEventArgs> e)
{
    System::Console::WriteLine(L"*** The storage is merging: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

void PstMerge_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e)
{
    if (currentFolder == nullptr)
    {
        currentFolder = e->get_DestinationFolder()->RetrieveFullPath();
    }

    System::String folderPath = e->get_DestinationFolder()->RetrieveFullPath();

    if (currentFolder != folderPath)
    {
        System::Console::WriteLine(L"    Added {0} messages to \"{1}\"", System::ObjectExt::Box<int32_t>(messageCount), System::ObjectExt::Box<System::String>(currentFolder));
        messageCount = 0;
        currentFolder = folderPath;
    }

    messageCount++;
    totalAdded++;
}


void MergeMultiplePSTsInToSinglePST()
{
    // ExStart:MergePSTFiles
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + L"Sub.pst";
    totalAdded = 0;
    try
    {
        {
            System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dst);
            
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
            // ------------------------------------------
            // The events subscription is an optional step for the tracking process only.
            personalStorage->StorageProcessed.connect(PstMerge_OnStorageProcessed);
            personalStorage->ItemMoved.connect(PstMerge_OnItemMoved);
            
            // Merges with the pst files that are located in separate folder. 
            personalStorage->MergeWith(System::IO::Directory::GetFiles(dataDir + L"MergePST\\"));
            System::Console::WriteLine(L"Total messages added: {0}", System::ObjectExt::Box<int32_t>(totalAdded));
        }
        System::Console::WriteLine(System::Environment::get_NewLine() + L"PST merged successfully at " + dst);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message() + L"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:MergePSTFiles
}








