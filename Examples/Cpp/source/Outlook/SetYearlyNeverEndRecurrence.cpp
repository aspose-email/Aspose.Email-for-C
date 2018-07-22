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
#include <Mapi/MapiTaskState.h>
#include <Mapi/MapiTask.h>
#include <Mapi/MapiCalendarRecurrencePatternType.h>
#include <Mapi/MapiCalendarRecurrencePattern.h>
#include <Mapi/MapiCalendarRecurrenceEndType.h>
#include <Mapi/MapiCalendarMonthlyRecurrencePattern.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void SetYearlyNeverEndRecurrence()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<System::TimeZone> localZone = System::TimeZone::get_CurrentTimeZone();
    System::TimeSpan timeSpan = localZone->GetUtcOffset(System::DateTime::get_Now());
    System::DateTime StartDate(2015, 7, 1);
    StartDate = StartDate.Add(timeSpan);
    
    System::DateTime DueDate(2015, 7, 1);
    System::DateTime endByDate(2020, 12, 31);
    DueDate = DueDate.Add(timeSpan);
    endByDate = endByDate.Add(timeSpan);
    
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(u"This is test task", u"Sample Body", StartDate, DueDate);
    task->set_State(Aspose::Email::Mapi::MapiTaskState::NotAssigned);
    
    // ExStart:SetYearlyNeverEndRecurrence
    // Set the Yearly recurrence
    auto recurrence = [&]{ auto tmp_0 = System::MakeObject<MapiCalendarMonthlyRecurrencePattern>(); tmp_0->set_Day(15); tmp_0->set_Period(12); tmp_0->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Month); tmp_0->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd); return tmp_0; }();
    // ExEnd:SetYearlyNeverEndRecurrence
    
    task->set_Recurrence(recurrence);
    if (recurrence->get_OccurrenceCount() == 0)
    {
        recurrence->set_OccurrenceCount(1);
    }
    
    //task.Save(dataDir + "SetYearlyNeverEndRecurrence_out.msg", TaskSaveFormat.Msg);
}

