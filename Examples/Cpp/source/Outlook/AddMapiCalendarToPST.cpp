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
#include <Mapi/MapiRecipientType.h>
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiCalendar.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void AddMapiCalendarToPST()
{
    // The path to the File directory.
    // ExStart:AddMapiCalendarToPST
    System::String dataDir = GetDataDir_Outlook();
    
    // Create the appointment
    System::SharedPtr<MapiCalendar> appointment = System::MakeObject<MapiCalendar>(u"LAKE ARGYLE WA 6743", u"Appointment", u"This is a very important meeting :)", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0));
    
    // Create the meeting
    System::SharedPtr<MapiRecipientCollection> attendees = System::MakeObject<MapiRecipientCollection>();
    attendees->Add(u"ReneeAJones@armyspy.com", u"Renee A. Jones", Aspose::Email::Mapi::MapiRecipientType::MAPI_TO);
    attendees->Add(u"SzllsyLiza@dayrep.com", u"Szollosy Liza", Aspose::Email::Mapi::MapiRecipientType::MAPI_TO);
    
    System::SharedPtr<MapiCalendar> meeting = System::MakeObject<MapiCalendar>(u"Meeting Room 3 at Office Headquarters", u"Meeting", u"Please confirm your availability.", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0), u"CharlieKhan@dayrep.com", attendees);
    
    System::String path = dataDir + u"AddMapiCalendarToPST_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dataDir + u"AddMapiCalendarToPST_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ pst});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> calendarFolder = pst->CreatePredefinedFolder(u"Calendar", Aspose::Email::Storage::Pst::StandardIpmFolder::Appointments);
            calendarFolder->AddMapiMessageItem(appointment);
            calendarFolder->AddMapiMessageItem(meeting);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:AddMapiCalendarToPST
}

