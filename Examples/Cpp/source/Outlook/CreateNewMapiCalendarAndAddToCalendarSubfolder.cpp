/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/NoteColor.h>
#include <Mapi/MapiNote.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/IMapiMessageItem.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void CreateNewMapiCalendarAndAddToCalendarSubfolder()
{
    // The path to the File directory.
    // ExStart:CreateNewMapiCalendarAndAddToCalendarSubfolder
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(dataDir + u"Note.msg");
    
    // Note #1
    System::SharedPtr<MapiNote> note1 = System::DynamicCast<Aspose::Email::Mapi::MapiNote>(message->ToMapiMessageItem());
    note1->set_Subject(u"Yellow color note");
    note1->set_Body(u"This is a yellow color note");
    
    // Note #2
    System::SharedPtr<MapiNote> note2 = System::DynamicCast<Aspose::Email::Mapi::MapiNote>(message->ToMapiMessageItem());
    note2->set_Subject(u"Pink color note");
    note2->set_Body(u"This is a pink color note");
    note2->set_Color(Aspose::Email::Mapi::NoteColor::Pink);
    
    // Note #3
    System::SharedPtr<MapiNote> note3 = System::DynamicCast<Aspose::Email::Mapi::MapiNote>(message->ToMapiMessageItem());
    note2->set_Subject(u"Blue color note");
    note2->set_Body(u"This is a blue color note");
    note2->set_Color(Aspose::Email::Mapi::NoteColor::Blue);
    note3->set_Height(500);
    note3->set_Width(500);
    
    if (System::IO::File::Exists(dataDir + u"SampleNote_out.pst"))
    {
        System::IO::File::Delete(dataDir + u"SampleNote_out.pst");
    }
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dataDir + u"SampleNote_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ pst});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> notesFolder = pst->CreatePredefinedFolder(u"Notes", Aspose::Email::Storage::Pst::StandardIpmFolder::Notes);
            notesFolder->AddMapiMessageItem(note1);
            notesFolder->AddMapiMessageItem(note2);
            notesFolder->AddMapiMessageItem(note3);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:CreateNewMapiCalendarAndAddToCalendarSubfolder
}

