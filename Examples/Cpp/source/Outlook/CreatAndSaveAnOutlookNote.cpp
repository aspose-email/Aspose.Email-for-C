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
#include <Formats/Outlook/Mapi/NoteSaveFormat.h>
#include <Formats/Outlook/Mapi/NoteColor.h>
#include <Formats/Outlook/Mapi/MapiNote.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void CreatAndSaveAnOutlookNote()
{
    // ExStart:CreatAndSaveAnOutlookNote
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    // Create MapiNote and set Properties 
    System::SharedPtr<MapiNote> note3 = System::MakeObject<MapiNote>();
    note3->set_Subject(L"Blue color note");
    note3->set_Body(L"This is a blue color note");
    note3->set_Color(Aspose::Email::Outlook::NoteColor::Blue);
    note3->set_Height(500);
    note3->set_Width(500);
    note3->Save(dataDir + L"MapiNote_out.msg", Aspose::Email::Outlook::NoteSaveFormat::Msg);
    // ExEnd:CreatAndSaveAnOutlookNote
}







