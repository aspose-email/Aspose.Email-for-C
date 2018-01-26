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
#include <system/date_time.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>
#include <Formats/Appointments/AppointmentSaveFormat.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void CreateAndSaveCalendaritems()
{
    //ExStart:CreateAndSaveCalendaritems
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create the appointment
    System::SharedPtr<MapiCalendar> calendar = System::MakeObject<MapiCalendar>(L"LAKE ARGYLE WA 6743", L"Appointment", L"This is a very important meeting :)", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0));
    
    calendar->Save(dataDir + L"CalendarItem_out.ics", Aspose::Email::Mail::AppointmentSaveFormat::Ics);
    //ExEnd:CreateAndSaveCalendaritems
}







