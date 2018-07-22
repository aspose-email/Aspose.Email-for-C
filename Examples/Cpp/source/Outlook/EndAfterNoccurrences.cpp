/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/timezone.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <Mapi/TaskSaveFormat.h>
#include <Mapi/MapiTaskState.h>
#include <Mapi/MapiTask.h>
#include <Mapi/MapiCalendarRecurrencePatternType.h>
#include <Mapi/MapiCalendarRecurrencePattern.h>
#include <Mapi/MapiCalendarRecurrenceEndType.h>
#include <Mapi/MapiCalendarDailyRecurrencePattern.h>
#include <cstdint>
#include <Calendar/Recurrences/DateCollection.h>
#include <Calendar/Recurrences/CalendarRecurrence.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Calendar::Recurrences;

static uint32_t GetOccurrenceCount(System::DateTime start, System::DateTime endBy, System::String rrule)
{
    // ExStart:GetOccurrenceCount
    System::SharedPtr<CalendarRecurrence> pattern = System::MakeObject<CalendarRecurrence>(System::String::Format(u"DTSTART:{0}\r\nRRULE:{1}", start.ToString(u"yyyyMMdd"), rrule));
    System::SharedPtr<DateCollection> dates = pattern->GenerateOccurrences(start, endBy);
    return (uint32_t)dates->get_Count();
    // ExEnd:GetOccurrenceCount
}


void EndAfterNoccurrences()
{
    // ExStart:EndAfterNoccurrences
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<System::TimeZone> localZone = System::TimeZone::get_CurrentTimeZone();
    System::TimeSpan timeSpan = localZone->GetUtcOffset(System::DateTime::get_Now());
    System::DateTime StartDate(2015, 7, 16);
    StartDate = StartDate.Add(timeSpan);
    
    System::DateTime DueDate(2015, 7, 16);
    System::DateTime endByDate(2015, 8, 1);
    DueDate = DueDate.Add(timeSpan);
    endByDate = endByDate.Add(timeSpan);
    
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(u"This is test task", u"Sample Body", StartDate, DueDate);
    task->set_State(Aspose::Email::Mapi::MapiTaskState::NotAssigned);
    
    // Set the Daily recurrence
    auto rec = [&]{ auto tmp_0 = System::MakeObject<MapiCalendarDailyRecurrencePattern>(); tmp_0->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Day); tmp_0->set_Period(1); tmp_0->set_WeekStartDay(System::DayOfWeek::Sunday); tmp_0->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::EndAfterNOccurrences); tmp_0->set_OccurrenceCount(GetOccurrenceCount(StartDate, endByDate, u"FREQ=DAILY")); return tmp_0; }();
    
    if (rec->get_OccurrenceCount() == 0)
    {
        rec->set_OccurrenceCount(1);
    }
    
    task->set_Recurrence(rec);
    task->Save(dataDir + u"Daily_out.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    // ExEnd:EndAfterNoccurrences
}


