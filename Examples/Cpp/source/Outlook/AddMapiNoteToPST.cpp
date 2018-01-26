/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/NoteColor.h>
#include <Formats/Outlook/Mapi/MapiNote.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/IMapiMessageItem.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void AddMapiNoteToPST()
{
    // ExStart:AddMapiNoteToPST
    // The path to the documents directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> mess = MapiMessage::FromFile(dataDir + L"Note.msg");
    
    // Create three Notes  
    System::SharedPtr<MapiNote> note1 = System::DynamicCast<Aspose::Email::Outlook::MapiNote>(mess->ToMapiMessageItem());
    note1->set_Subject(L"Yellow color note");
    note1->set_Body(L"This is a yellow color note");
    
    System::SharedPtr<MapiNote> note2 = System::DynamicCast<Aspose::Email::Outlook::MapiNote>(mess->ToMapiMessageItem());
    note2->set_Subject(L"Pink color note");
    note2->set_Body(L"This is a pink color note");
    note2->set_Color(Aspose::Email::Outlook::NoteColor::Pink);
    
    System::SharedPtr<MapiNote> note3 = System::DynamicCast<Aspose::Email::Outlook::MapiNote>(mess->ToMapiMessageItem());
    note2->set_Subject(L"Blue color note");
    note2->set_Body(L"This is a blue color note");
    note2->set_Color(Aspose::Email::Outlook::NoteColor::Blue);
    note3->set_Height(500);
    note3->set_Width(500);
    
    System::String path = dataDir + L"AddMapiNoteToPST_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"AddMapiNoteToPST_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> notesFolder = personalStorage->CreatePredefinedFolder(L"Notes", Aspose::Email::Outlook::Pst::StandardIpmFolder::Notes);
        notesFolder->AddMapiMessageItem(note1);
        notesFolder->AddMapiMessageItem(note2);
        notesFolder->AddMapiMessageItem(note3);
    }
    // ExEnd:AddMapiNoteToPST
}







