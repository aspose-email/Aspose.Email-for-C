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
#include <system/date_time.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/MapiJournal.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void CreateNewMapiJournalAndAddToSubfolder()
{
    // The path to the File directory.
    // ExStart:CreateNewMapiJournalAndAddToSubfolder
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiJournal> journal = System::MakeObject<MapiJournal>(L"daily record", L"called out in the dark", L"Phone call", L"Phone call");
    journal->set_StartTime(System::DateTime::get_Now());
    journal->set_EndTime(journal->get_StartTime().AddHours(1));
    
    System::String path = dataDir + L"CreateNewMapiJournalAndAddToSubfolder_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"CreateNewMapiJournalAndAddToSubfolder_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> journalFolder = personalStorage->CreatePredefinedFolder(L"Journal", Aspose::Email::Outlook::Pst::StandardIpmFolder::Journal);
        journalFolder->AddMapiMessageItem(journal);
    }
    // ExEnd:CreateNewMapiJournalAndAddToSubfolder
}







