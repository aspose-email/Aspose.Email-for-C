/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;
using namespace Aspose::Email::Tools::Search;

void SearchStringInPSTWithIgnoreCaseParameter()
{
    // The path to the File directory.
    // ExStart:SearchStringInPSTWithIgnoreCaseParameter
    System::String dataDir = GetDataDir_Outlook();
    
    System::String path = dataDir + u"SearchStringInPSTWithIgnoreCaseParameter_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"SearchStringInPSTWithIgnoreCaseParameter_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> folderInfo = personalStorage->CreatePredefinedFolder(u"Inbox", Aspose::Email::Storage::Pst::StandardIpmFolder::Inbox);
            
            folderInfo->AddMessage(MapiMessage::FromMailMessage(MailMessage::Load(dataDir + u"Message.eml")));
            
            System::SharedPtr<PersonalStorageQueryBuilder> builder = System::MakeObject<PersonalStorageQueryBuilder>();
            // IgnoreCase is True
            builder->get_From()->Contains(u"automated", true);
            
            System::SharedPtr<MailQuery> query = builder->GetQuery();
            System::SharedPtr<MessageInfoCollection> coll = folderInfo->GetContents(query);
            System::Console::WriteLine(coll->get_Count());
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:SearchStringInPSTWithIgnoreCaseParameter
}

