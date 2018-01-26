/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
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
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/FolderKind.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;




void WalkFolders(System::SharedPtr<Aspose::Email::Outlook::Pst::FolderInfo> folder, System::String parentFolderName, System::SharedPtr<System::Collections::Generic::IList<System::String>> folderData)
{
    System::String displayName = (System::String::IsNullOrEmpty(folder->get_DisplayName())) ? L"ROOT" : folder->get_DisplayName();
    System::String folderNames = System::String::Format(L"DisplayName = {0}; Parent.DisplayName = {1}",displayName,parentFolderName);
    folderData->Add(folderNames);
    if (displayName == L"Finder")
    {
        System::Console::WriteLine(L"Test this case");
    }
    
    if (!folder->get_HasSubFolders())
    {
        return;
    }
    System::SharedPtr<FolderInfoCollection> coll = folder->GetSubFolders(Aspose::Email::Outlook::Pst::FolderKind::Search | Aspose::Email::Outlook::Pst::FolderKind::Normal);
    
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
    System::String path = dataDir + L"PersonalStorage.pst";
    System::ArrayPtr<uint8_t> buffer = System::IO::File::ReadAllBytes(path);
    {
        System::SharedPtr<System::IO::Stream> s = System::IO::File::OpenRead(path);

        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ s, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromStream(s);

        // One sample of the sub-folder EntryId which could not be retrieved in Finder sub-folder
        System::SharedPtr<FolderInfo> target = pst->GetFolderById(L"AAAAAB9of1CGOidPhTb686WQY68igAAA");
        System::SharedPtr<System::Collections::Generic::IList<System::String>> folderData = System::MakeObject<System::Collections::Generic::List<System::String>>();
        WalkFolders(pst->get_RootFolder(), L"N/A", folderData);
    }
}


void ParseSearchableFolders()
{
    WalkAllFolders();
}






