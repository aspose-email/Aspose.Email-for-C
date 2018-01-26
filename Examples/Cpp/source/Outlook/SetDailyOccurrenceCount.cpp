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
#include <Formats/Outlook/Mapi/TaskSaveFormat.h>
#include <Formats/Outlook/Mapi/MapiTaskState.h>
#include <Formats/Outlook/Mapi/MapiTask.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePatternType.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrenceEndType.h>
#include <Formats/Outlook/Mapi/MapiCalendarDailyRecurrencePattern.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void SetDailyOccurrenceCount()
{
    System::String dataDir = GetDataDir_Outlook();
    
    System::DateTime StartDate(2015, 7, 16);
    System::DateTime endByDate(2015, 8, 1);
    System::DateTime DueDate(2015, 7, 16);
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(L"This is test task", L"Sample Body", StartDate, DueDate);
    task->set_State(Aspose::Email::Outlook::MapiTaskState::NotAssigned);
    
    // ExStart:SetDailyOccurrenceCount
    // Set the Daily recurrence
    auto record = [&]{ auto tmp_0 = System::MakeObject<MapiCalendarDailyRecurrencePattern>(); tmp_0->set_PatternType(Aspose::Email::Outlook::MapiCalendarRecurrencePatternType::Day); tmp_0->set_Period(1); tmp_0->set_WeekStartDay(System::DayOfWeek::Sunday); tmp_0->set_EndType(Aspose::Email::Outlook::MapiCalendarRecurrenceEndType::EndAfterNOccurrences); tmp_0->set_OccurrenceCount(5); return tmp_0; }();
    task->set_Recurrence(record);
    // ExEnd:SetDailyOccurrenceCount
    
    task->Save(dataDir + L"SetDailyOccurrenceCount_out.msg", Aspose::Email::Outlook::TaskSaveFormat::Msg);
}







