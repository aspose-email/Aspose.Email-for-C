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
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Protocols/Base/Search/StringComparisonField.h>
#include <Protocols/Base/Search/MailQuery.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Formats/Outlook/Pst/PersonalStorageQueryBuilder.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void SearchStringInPSTWithIgnoreCaseParameter()
{
    // The path to the File directory.
    // ExStart:SearchStringInPSTWithIgnoreCaseParameter
    System::String dataDir = GetDataDir_Outlook();
    
    System::String path = dataDir + L"SearchStringInPSTWithIgnoreCaseParameter_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"SearchStringInPSTWithIgnoreCaseParameter_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> folderInfo = personalStorage->CreatePredefinedFolder(L"Inbox", Aspose::Email::Outlook::Pst::StandardIpmFolder::Inbox);
        
        folderInfo->AddMessage(MapiMessage::FromMailMessage(MailMessage::Load(dataDir + L"Message.eml")));
        
        System::SharedPtr<PersonalStorageQueryBuilder> builder = System::MakeObject<PersonalStorageQueryBuilder>();
        // IgnoreCase is True
        builder->get_From()->Contains(L"automated", true);
        
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<MessageInfoCollection> coll = folderInfo->GetContents(query);
        System::Console::WriteLine(coll->get_Count());
    }
    // ExEnd:SearchStringInPSTWithIgnoreCaseParameter
}







