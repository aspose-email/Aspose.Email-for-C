#if 0 //TEMPORARY OFF
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <Mapi/MapiCalendarRecurrencePatternFactory.h>
#include <Mapi/MapiCalendarRecurrencePattern.h>
#include <Mapi/MapiCalendarEventRecurrence.h>
#include <Mapi/MapiCalendar.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void GenerateRecurrenceFromRecurrenceRule()
{
    // ExStart:GenerateRecurrenceFromRecurrenceRule
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::DateTime startDate(2015, 7, 16);
    System::DateTime endDate(2015, 8, 1);
    System::SharedPtr<MapiCalendar> app1 = System::MakeObject<MapiCalendar>(u"test location", u"test summary", u"test description", startDate, endDate);
    
    app1->set_StartDate(startDate);
    app1->set_EndDate(endDate);
    
    System::String pattern = u"DTSTART;TZID=Europe/London:20150831T080000\r\nDTEND;TZID=Europe/London:20150831T083000\r\nRRULE:FREQ=DAILY;INTERVAL=1;COUNT=7\r\nEXDATE:20150831T070000Z,20150904T070000Z";
    app1->get_Recurrence()->set_RecurrencePattern(MapiCalendarRecurrencePatternFactory::FromString(pattern));
    // ExEnd:GenerateRecurrenceFromRecurrenceRule
}
#endif
