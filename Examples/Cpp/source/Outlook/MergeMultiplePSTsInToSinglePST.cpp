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
#include <Storage/Pst/StorageProcessedEventArgs.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/ItemMovedEventArgs.h>
#include <Storage/Pst/FolderInfo.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

static int32_t totalAdded = 0;
static System::String currentFolder;
static int32_t messageCount = 0;

static void PstMerge_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::StorageProcessedEventArgs> e)
{
    System::Console::WriteLine(u"*** The storage is merging: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

void PstMerge_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::ItemMovedEventArgs> e)
{
    if (currentFolder == nullptr)
    {
        currentFolder = e->get_DestinationFolder()->RetrieveFullPath();
    }
    
    System::String folderPath = e->get_DestinationFolder()->RetrieveFullPath();
    
    if (currentFolder != folderPath)
    {
        System::Console::WriteLine(u"    Added {0} messages to \"{1}\"", System::ObjectExt::Box<int32_t>(messageCount), System::ObjectExt::Box<System::String>(currentFolder));
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
    System::String dst = dataDir + u"Sub.pst";
    totalAdded = 0;
    try
    {
        {
            System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dst);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage });
            // ------------------------------------------

            try
            {
                // The events subscription is an optional step for the tracking process only.
                personalStorage->StorageProcessed.connect(PstMerge_OnStorageProcessed);
                personalStorage->ItemMoved.connect(PstMerge_OnItemMoved);

                // Merges with the pst files that are located in separate folder. 
                personalStorage->MergeWith(System::IO::Directory::GetFiles(dataDir + u"MergePST\\"));
                System::Console::WriteLine(u"Total messages added: {0}", System::ObjectExt::Box<int32_t>(totalAdded));
            }
            catch (...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        System::Console::WriteLine(System::Environment::get_NewLine() + u"PST merged successfully at " + dst);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message() + u"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }

    // ExEnd:MergePSTFiles
}
