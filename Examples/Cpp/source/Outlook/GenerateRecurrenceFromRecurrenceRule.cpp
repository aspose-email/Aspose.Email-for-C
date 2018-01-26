/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePatternFactory.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiCalendarEventRecurrence.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void GenerateRecurrenceFromRecurrenceRule()
{
    // ExStart:GenerateRecurrenceFromRecurrenceRule
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::DateTime startDate(2015, 7, 16);
    System::DateTime endDate(2015, 8, 1);
    System::SharedPtr<MapiCalendar> app1 = System::MakeObject<MapiCalendar>(L"test location", L"test summary", L"test description", startDate, endDate);
    
    app1->set_StartDate(startDate);
    app1->set_EndDate(endDate);
    
    System::String pattern = L"DTSTART;TZID=Europe/London:20150831T080000\r\nDTEND;TZID=Europe/London:20150831T083000\r\nRRULE:FREQ=DAILY;INTERVAL=1;COUNT=7\r\nEXDATE:20150831T070000Z,20150904T070000Z";
    app1->get_Recurrence()->set_RecurrencePattern(MapiCalendarRecurrencePatternFactory::FromString(pattern));
    // ExEnd:GenerateRecurrenceFromRecurrenceRule
}







