/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ilist.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderKind.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void WalkFolders(System::SharedPtr<Aspose::Email::Storage::Pst::FolderInfo> folder, System::String parentFolderName, System::SharedPtr<System::Collections::Generic::IList<System::String>> folderData)
{
    System::String displayName = (System::String::IsNullOrEmpty(folder->get_DisplayName())) ? u"ROOT" : folder->get_DisplayName();
    System::String folderNames = System::String::Format(u"DisplayName = {0}; Parent.DisplayName = {1}", displayName, parentFolderName);
    folderData->Add(folderNames);
    if (displayName == u"Finder")
    {
        System::Console::WriteLine(u"Test this case");
    }

    if (!folder->get_HasSubFolders())
    {
        return;
    }
    System::SharedPtr<FolderInfoCollection> coll = folder->GetSubFolders(Aspose::Email::Storage::Pst::FolderKind::Search | Aspose::Email::Storage::Pst::FolderKind::Normal);

    {
        auto subfolder_enumerator = (coll)->GetEnumerator();
        decltype(subfolder_enumerator->get_Current()) subfolder;
        while (subfolder_enumerator->MoveNext() && (subfolder = subfolder_enumerator->get_Current(), true))
        {
            WalkFolders(subfolder, displayName, folderData);
        }
    }
}

void WalkAllFolders()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String path = dataDir + u"PersonalStorage.pst";
    System::ArrayPtr<uint8_t> buffer = System::IO::File::ReadAllBytes(path);
    {
        System::SharedPtr<System::IO::Stream> s = System::IO::File::OpenRead(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ s});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromStream(s);
            
            // One sample of the sub-folder EntryId which could not be retrieved in Finder sub-folder
            System::SharedPtr<FolderInfo> target = pst->GetFolderById(u"AAAAAB9of1CGOidPhTb686WQY68igAAA");
            System::SharedPtr<System::Collections::Generic::IList<System::String>> folderData = System::MakeObject<System::Collections::Generic::List<System::String>>();
            WalkFolders(pst->get_RootFolder(), u"N/A", folderData);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
}


void ParseSearchableFolders()
{
    WalkAllFolders();
}
