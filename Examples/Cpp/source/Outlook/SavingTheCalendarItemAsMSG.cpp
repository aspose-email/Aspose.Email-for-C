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
#include <system/date_time.h>
#include <Mapi/MapiCalendar.h>
#include <Calendar/AppointmentSaveFormat.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Calendar;

void SavingTheCalendarItemAsMSG()
{
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiCalendar> calendar = System::MakeObject<MapiCalendar>(u"LAKE ARGYLE WA 6743", u"Appointment", u"This is a very important meeting :)", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0));
    
    // ExStart:SavingTheCalendarItemAsMSG
    calendar->Save(dataDir + u"CalendarItemAsMSG_out.Msg", Aspose::Email::Calendar::AppointmentSaveFormat::Msg);
    // ExEnd:SavingTheCalendarItemAsMSG
}

