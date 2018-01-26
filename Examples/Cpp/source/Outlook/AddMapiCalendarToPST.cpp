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
#include <Formats/Outlook/Mapi/MapiRecipientType.h>
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void AddMapiCalendarToPST()
{
    // The path to the File directory.
    // ExStart:AddMapiCalendarToPST
    System::String dataDir = GetDataDir_Outlook();
    
    // Create the appointment
    System::SharedPtr<MapiCalendar> appointment = System::MakeObject<MapiCalendar>(L"LAKE ARGYLE WA 6743", L"Appointment", L"This is a very important meeting :)", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0));
    
    // Create the meeting
    System::SharedPtr<MapiRecipientCollection> attendees = System::MakeObject<MapiRecipientCollection>();
    attendees->Add(L"ReneeAJones@armyspy.com", L"Renee A. Jones", Aspose::Email::Outlook::MapiRecipientType::MAPI_TO);
    attendees->Add(L"SzllsyLiza@dayrep.com", L"Szollosy Liza", Aspose::Email::Outlook::MapiRecipientType::MAPI_TO);
    
    System::SharedPtr<MapiCalendar> meeting = System::MakeObject<MapiCalendar>(L"Meeting Room 3 at Office Headquarters", L"Meeting", L"Please confirm your availability.", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0), L"CharlieKhan@dayrep.com", attendees);
    
    System::String path = dataDir + L"AddMapiCalendarToPST_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dataDir + L"AddMapiCalendarToPST_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> calendarFolder = pst->CreatePredefinedFolder(L"Calendar", Aspose::Email::Outlook::Pst::StandardIpmFolder::Appointments);
        calendarFolder->AddMapiMessageItem(appointment);
        calendarFolder->AddMapiMessageItem(meeting);
    }
    // ExEnd:AddMapiCalendarToPST
}







