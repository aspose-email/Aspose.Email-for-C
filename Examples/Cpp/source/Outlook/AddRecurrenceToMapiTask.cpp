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
#include <system/enum_helpers.h>
#include <system/date_time.h>
#include <Mapi/TaskSaveFormat.h>
#include <Mapi/MapiTaskState.h>
#include <Mapi/MapiTask.h>
#include <Mapi/MapiCalendarWeeklyRecurrencePattern.h>
#include <Mapi/MapiCalendarRecurrencePatternType.h>
#include <Mapi/MapiCalendarRecurrencePattern.h>
#include <Mapi/MapiCalendarRecurrenceEndType.h>
#include <Mapi/MapiCalendarMonthlyRecurrencePattern.h>
#include <Mapi/MapiCalendarDayOfWeek.h>
#include <Mapi/MapiCalendarDailyRecurrencePattern.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void AddRecurrenceToMapiTask()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:AddRecurrenceToMapiTask
    System::DateTime startDate(2015, 4, 30, 10, 00, 00);
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(u"abc", u"def", startDate, startDate.AddHours(1));
    task->set_State(Aspose::Email::Mapi::MapiTaskState::NotAssigned);
    
    // Set the weekly recurrence
    auto rec = [&]{ auto tmp_0 = System::MakeObject<MapiCalendarDailyRecurrencePattern>(); tmp_0->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Day); tmp_0->set_Period(1); tmp_0->set_WeekStartDay(System::DayOfWeek::Sunday); tmp_0->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd); tmp_0->set_OccurrenceCount(0); return tmp_0; }();
    task->set_Recurrence(rec);
    task->Save(dataDir + u"AsposeDaily_out.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    
    // Set the weekly recurrence
    auto rec1 = [&]{ auto tmp_1 = System::MakeObject<MapiCalendarWeeklyRecurrencePattern>(); tmp_1->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Week); tmp_1->set_Period(1); tmp_1->set_DayOfWeek(Aspose::Email::Mapi::MapiCalendarDayOfWeek::Wednesday); tmp_1->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd); tmp_1->set_OccurrenceCount(0); return tmp_1; }();
    task->set_Recurrence(rec1);
    task->Save(dataDir + u"AsposeWeekly_out.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    
    // Set the monthly recurrence
    auto recMonthly = [&]{ auto tmp_2 = System::MakeObject<MapiCalendarMonthlyRecurrencePattern>(); tmp_2->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Month); tmp_2->set_Period(1); tmp_2->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd); tmp_2->set_Day(30); tmp_2->set_OccurrenceCount(0); tmp_2->set_WeekStartDay(System::DayOfWeek::Sunday); return tmp_2; }();
    task->set_Recurrence(recMonthly);
    //task.Save(dataDir + "AsposeMonthly_out.msg", TaskSaveFormat.Msg);
    
    // Set the yearly recurrence
    auto recYearly = [&]{ auto tmp_3 = System::MakeObject<MapiCalendarMonthlyRecurrencePattern>(); tmp_3->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Month); tmp_3->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd); tmp_3->set_OccurrenceCount(10); tmp_3->set_Period(12); return tmp_3; }();
    task->set_Recurrence(recYearly);
    //task.Save(dataDir + "AsposeYearly_out.msg", TaskSaveFormat.Msg);
    // ExEnd:AddRecurrenceToMapiTask
}

