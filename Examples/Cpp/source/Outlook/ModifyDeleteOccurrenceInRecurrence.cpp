/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/setters_wrap.h>
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/collections/ilist.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiRecipientType.h>
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiCalendarRecurrencePatternType.h>
#include <Mapi/MapiCalendarRecurrencePattern.h>
#include <Mapi/MapiCalendarRecurrenceEndType.h>
#include <Mapi/MapiCalendarExceptionInfo.h>
#include <Mapi/MapiCalendarEventRecurrence.h>
#include <Mapi/MapiCalendarDailyRecurrencePattern.h>
#include <Mapi/MapiCalendar.h>
#include <cstdint>


using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void ModifyDeleteOccurrenceInRecurrence()
{
    //ExStart: ModifyDeleteOccurrenceInRecurrence
    System::DateTime startDate = System::DateTime::get_Now().get_Date().AddHours(12);
    
    System::SharedPtr<MapiCalendarEventRecurrence> recurrence = System::MakeObject<MapiCalendarEventRecurrence>();
    System::SharedPtr<MapiCalendarRecurrencePattern> pattern = System::setter_wrap(recurrence.GetPointer(), &MapiCalendarEventRecurrence::set_RecurrencePattern, System::MakeObject<MapiCalendarDailyRecurrencePattern>());
    pattern->set_PatternType(Aspose::Email::Mapi::MapiCalendarRecurrencePatternType::Day);
    pattern->set_Period(1);
    pattern->set_EndType(Aspose::Email::Mapi::MapiCalendarRecurrenceEndType::NeverEnd);
    
    System::DateTime exceptionDate = startDate.AddDays(1);
    
    // adding one exception
    pattern->get_Exceptions()->Add([&]{ auto tmp_0 = System::MakeObject<MapiCalendarExceptionInfo>(); tmp_0->set_Location(u"London"); tmp_0->set_Subject(u"Subj"); tmp_0->set_OriginalStartDate(exceptionDate); tmp_0->set_StartDateTime(exceptionDate); tmp_0->set_EndDateTime(exceptionDate.AddHours(5)); return tmp_0; }());
    pattern->get_ModifiedInstanceDates()->Add(exceptionDate);
    // every modified instance also has to have an entry in the DeletedInstanceDates field with the original instance date.
    pattern->get_DeletedInstanceDates()->Add(exceptionDate);
    
    // adding one deleted instance
    pattern->get_DeletedInstanceDates()->Add(exceptionDate.AddDays(2));
    
    
    System::SharedPtr<MapiRecipientCollection> recColl = System::MakeObject<MapiRecipientCollection>();
    recColl->Add(u"receiver@domain.com", u"receiver", Aspose::Email::Mapi::MapiRecipientType::MAPI_TO);
    System::SharedPtr<MapiCalendar> newCal = System::MakeObject<MapiCalendar>(u"This is Location", u"This is Summary", u"This is recurrence test", startDate, startDate.AddHours(3), u"organizer@domain.com", recColl);
    newCal->set_Recurrence(recurrence);
    
    {
        System::SharedPtr<System::IO::MemoryStream> memory = System::MakeObject<System::IO::MemoryStream>();
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ memory});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(memory, Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
            System::SharedPtr<FolderInfo> calendarFolder = pst->CreatePredefinedFolder(u"Calendar", Aspose::Email::Storage::Pst::StandardIpmFolder::Appointments);
            calendarFolder->AddMapiMessageItem(newCal);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    //ExEnd: ModifyDeleteOccurrenceInRecurrence
}

