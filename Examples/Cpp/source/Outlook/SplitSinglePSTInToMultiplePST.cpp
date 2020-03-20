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
#include <system/io/file.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
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

static int32_t messageCount = 0;
static System::String currentFolder;
static int32_t totalAdded = 0;

static void destinationFolder_ItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::ItemMovedEventArgs> e)
{
    totalAdded++;
}

static void PstMerge_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::StorageProcessedEventArgs> e)
{
    System::Console::WriteLine(u"*** The storage is merging: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

static void PstMerge_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::ItemMovedEventArgs> e)
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

void PstSplit_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::StorageProcessedEventArgs> e)
{
    if (currentFolder != nullptr)
    {
        System::Console::WriteLine(u"    Added {0} messages to \"{1}\"", System::ObjectExt::Box<int32_t>(messageCount), System::ObjectExt::Box<System::String>(currentFolder));
    }
    
    messageCount = 0;
    currentFolder.reset();
    System::Console::WriteLine(u"*** The chunk is processed: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

void PstSplit_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::ItemMovedEventArgs> e)
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
}


void SplitSinglePSTInToMultiplePST()
{
    // The path to the File directory.
    // ExStart:SplitSinglePSTInToMultiplePST
    System::String dataDir = GetDataDir_Outlook();
    try
    {
        System::String dstSplit = dataDir + System::Convert::ToString(u"Chunks\\");

        // Delete the files if already present

        {
            const System::ArrayPtr<System::String>& array_ = System::IO::Directory::GetFiles(dstSplit);
            for (int i_ = 0; i_ < array_->Count(); ++i_)
            {
                System::String file__1 = array_[i_];
                {
                    System::IO::File::Delete(file__1);
                }
            }
        }

        {
            System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"Sub.pst");
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage });
            // ------------------------------------------

            try
            {
                // The events subscription is an optional step for the tracking process only.
                personalStorage->StorageProcessed.connect(PstSplit_OnStorageProcessed);
                personalStorage->ItemMoved.connect(PstSplit_OnItemMoved);

                // Splits into pst chunks with the size of 5mb
                personalStorage->SplitInto(5000000, dataDir + u"\\Chunks\\");
            }
            catch (...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }

    // ExEnd:SplitSinglePSTInToMultiplePST
}

