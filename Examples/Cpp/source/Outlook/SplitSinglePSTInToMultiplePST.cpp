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
#include <system/io/file.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
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


class SplitSinglePSTInToMultiplePST
{
public:

    int32_t totalAdded;
    static int32_t messageCount;
    static System::String currentFolder;

    SplitSinglePSTInToMultiplePST();

    void destinationFolder_ItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e);
    void PstMerge_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::StorageProcessedEventArgs> e);
    void PstMerge_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e);
    static void PstSplit_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::StorageProcessedEventArgs> e);
    static void PstSplit_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e);

};


int32_t SplitSinglePSTInToMultiplePST::messageCount = 0;
System::String SplitSinglePSTInToMultiplePST::currentFolder;

void SplitSinglePSTInToMultiplePST()
{
    // The path to the File directory.
    // ExStart:SplitSinglePSTInToMultiplePST
    System::String dataDir = GetDataDir_Outlook();
    try
    {
        System::String dstSplit = dataDir + L"Chunks\\";
        // Convert.ToString("Chunks\\");
        
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
            System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + L"Sub.pst");
            
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
            // ------------------------------------------
            // The events subscription is an optional step for the tracking process only.
            personalStorage->StorageProcessed.connect(SplitSinglePSTInToMultiplePST::PstSplit_OnStorageProcessed);
            personalStorage->ItemMoved.connect(SplitSinglePSTInToMultiplePST::PstSplit_OnItemMoved);
            
            // Splits into pst chunks with the size of 5mb
            personalStorage->SplitInto(5000000, dataDir + L"\\Chunks\\");
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message() + L"\nThis example will only work if you apply a valid Aspose Email License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:SplitSinglePSTInToMultiplePST
}

void SplitSinglePSTInToMultiplePST::destinationFolder_ItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e)
{
    totalAdded++;
}

void SplitSinglePSTInToMultiplePST::PstMerge_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::StorageProcessedEventArgs> e)
{
    System::Console::WriteLine(L"*** The storage is merging: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

void SplitSinglePSTInToMultiplePST::PstMerge_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e)
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

void SplitSinglePSTInToMultiplePST::PstSplit_OnStorageProcessed(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::StorageProcessedEventArgs> e)
{
    if (currentFolder != nullptr)
    {
        System::Console::WriteLine(L"    Added {0} messages to \"{1}\"", System::ObjectExt::Box<int32_t>(messageCount), System::ObjectExt::Box<System::String>(currentFolder));
    }
    
    messageCount = 0;
    currentFolder.reset();
    System::Console::WriteLine(L"*** The chunk is processed: {0}", System::ObjectExt::Box<System::String>(e->get_FileName()));
}

void SplitSinglePSTInToMultiplePST::PstSplit_OnItemMoved(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::ItemMovedEventArgs> e)
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
}

SplitSinglePSTInToMultiplePST::SplitSinglePSTInToMultiplePST() : totalAdded(0) { }







