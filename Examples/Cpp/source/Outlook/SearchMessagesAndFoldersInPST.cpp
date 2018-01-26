/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Protocols/Base/Search/StringComparisonField.h>
#include <Protocols/Base/Search/MailQuery.h>
#include <Protocols/Base/Search/IntComparisonField.h>
#include <Formats/Outlook/Pst/PersonalStorageQueryBuilder.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/MapiImportance.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void SearchMessagesAndFoldersInPST()
{
    
    // ExStart:SearchMessagesAndFoldersInPST
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + L"Outlook.pst");
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->GetSubFolder(L"Inbox");
        System::SharedPtr<PersonalStorageQueryBuilder> builder = System::MakeObject<PersonalStorageQueryBuilder>();
        
        // High importance messages
        builder->get_Importance()->Equals((int32_t)Aspose::Email::Outlook::Pst::MapiImportance::High);
        System::SharedPtr<MessageInfoCollection> messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Messages with High Imp:") + messages->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        builder->get_MessageClass()->Equals(L"IPM.Note");
        messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Messages with IPM.Note:") + messages->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // Messages with attachments AND high importance
        builder->get_Importance()->Equals((int32_t)Aspose::Email::Outlook::Pst::MapiImportance::High);
        builder->HasFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_HASATTACH);
        messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Messages with atts: ") + messages->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // Messages with size > 15 KB
        builder->get_MessageSize()->Greater(15000);
        messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"messags size > 15Kb:") + messages->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // Unread messages
        builder->HasNoFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_READ);
        messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Unread:") + messages->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // Unread messages with attachments
        builder->HasNoFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_READ);
        builder->HasFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_HASATTACH);
        messages = folder->GetContents(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Unread msgs with atts: ") + messages->get_Count());
        
        // Folder with name of 'SubInbox'
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        builder->get_FolderName()->Equals(L"SubInbox");
        System::SharedPtr<FolderInfoCollection> folders = folder->GetSubFolders(builder->GetQuery());
        System::Console::WriteLine(System::String(L"Folder having subfolder: ") + folders->get_Count());
        
        builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // Folders with subfolders
        builder->HasSubfolders();
        folders = folder->GetSubFolders(builder->GetQuery());
        System::Console::WriteLine(folders->get_Count());
    }
    // ExEnd:SearchMessagesAndFoldersInPST
}







