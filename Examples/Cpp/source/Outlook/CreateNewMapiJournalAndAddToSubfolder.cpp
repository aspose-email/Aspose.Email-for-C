/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiJournal.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void CreateNewMapiJournalAndAddToSubfolder()
{
    // The path to the File directory.
    // ExStart:CreateNewMapiJournalAndAddToSubfolder
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiJournal> journal = System::MakeObject<MapiJournal>(u"daily record", u"called out in the dark", u"Phone call", u"Phone call");
    journal->set_StartTime(System::DateTime::get_Now());
    journal->set_EndTime(journal->get_StartTime().AddHours(1));
    
    System::String path = dataDir + u"CreateNewMapiJournalAndAddToSubfolder_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"CreateNewMapiJournalAndAddToSubfolder_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> journalFolder = personalStorage->CreatePredefinedFolder(u"Journal", Aspose::Email::Storage::Pst::StandardIpmFolder::Journal);
            journalFolder->AddMapiMessageItem(journal);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:CreateNewMapiJournalAndAddToSubfolder
}

