/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/IntComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MapiImportance.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessageFlags.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void SearchMessagesAndFoldersInPST()
{
    
    // ExStart:SearchMessagesAndFoldersInPST
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"Outlook.pst");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
            System::SharedPtr<PersonalStorageQueryBuilder> builder = System::MakeObject<PersonalStorageQueryBuilder>();
            
            // High importance messages
            builder->get_Importance()->Equals((int32_t)Aspose::Email::Storage::Pst::MapiImportance::High);
            System::SharedPtr<MessageInfoCollection> messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Messages with High Imp:") + messages->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            builder->get_MessageClass()->Equals(u"IPM.Note");
            messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Messages with IPM.Note:") + messages->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // Messages with attachments AND high importance
            builder->get_Importance()->Equals((int32_t)Aspose::Email::Storage::Pst::MapiImportance::High);
            builder->HasFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_HASATTACH);
            messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Messages with atts: ") + messages->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // Messages with size > 15 KB
            builder->get_MessageSize()->Greater(15000);
            messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"messags size > 15Kb:") + messages->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // Unread messages
            builder->HasNoFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_READ);
            messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Unread:") + messages->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // Unread messages with attachments
            builder->HasNoFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_READ);
            builder->HasFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_HASATTACH);
            messages = folder->GetContents(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Unread msgs with atts: ") + messages->get_Count());
            
            // Folder with name of 'SubInbox'
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            builder->get_FolderName()->Equals(u"SubInbox");
            System::SharedPtr<FolderInfoCollection> folders = folder->GetSubFolders(builder->GetQuery());
            System::Console::WriteLine(System::String(u"Folder having subfolder: ") + folders->get_Count());
            
            builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // Folders with subfolders
            builder->HasSubfolders();
            folders = folder->GetSubFolders(builder->GetQuery());
            System::Console::WriteLine(folders->get_Count());
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:SearchMessagesAndFoldersInPST
}

