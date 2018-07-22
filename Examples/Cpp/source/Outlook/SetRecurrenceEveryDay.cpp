/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

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
    System::SharedPtr<CalendarRecurrence> pattern = System::MakeObject<CalendarRecurrence>(System::String::Format(u"DTSTART:{0}\r\nRRULE:{1}", start.ToString(u"yyyyMMdd"), rrule));
    System::SharedPtr<DateCollection> dates = pattern->GenerateOccurrences(start, endBy);
    return (uint32_t)dates->get_Count();
}

void SetRecurrenceEveryDay()
{
    System::String dataDir = GetDataDir_Outlook();
    
    System::DateTime StartDate(2015, 7, 16);
    System::DateTime endByDate(2015, 8, 1);
    System::DateTime DueDate(2015, 7, 16);
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(u"This is test task", u"Sample Body", StartDate, DueDate);
    task->set_State(Aspose::Email::Mapi::MapiTaskState::NotAssigned);
    
    // ExStart:SetRecurrenceEveryDay
    // Set the Daily recurrence
    auto record = [&]{ auto tmp_0 = System::MakeObject<MapiCalendarDailyRecurrencePattern>(); tmp_0->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Day); tmp_0->set_Period(1); tmp_0->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::EndAfterDate); tmp_0->set_OccurrenceCount(GetOccurrenceCount(StartDate, endByDate, u"FREQ=DAILY;INTERVAL=1")); tmp_0->set_EndDate(endByDate); return tmp_0; }();
    // ExEnd:SetRecurrenceEveryDay
    
    task->set_Recurrence(record);
    task->Save(dataDir + u"SetRecurrenceEveryDay_out.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    
    // ExStart:SetRecurrenceEveryDayInterval
    // Set the Daily recurrence
    auto record1 = [&]{ auto tmp_1 = System::MakeObject<MapiCalendarDailyRecurrencePattern>(); tmp_1->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Day); tmp_1->set_Period(2); tmp_1->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::EndAfterDate); tmp_1->set_OccurrenceCount(GetOccurrenceCount(StartDate, endByDate, u"FREQ=DAILY;INTERVAL=2")); tmp_1->set_EndDate(endByDate); return tmp_1; }();
    // ExEnd:SetRecurrenceEveryDayInterval
    
    task->set_Recurrence(record);
    task->Save(dataDir + u"SetRecurrenceEveryDayInterval_out.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    
}


