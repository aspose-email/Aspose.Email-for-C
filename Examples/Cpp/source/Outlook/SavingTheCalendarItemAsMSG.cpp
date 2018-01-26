//using Aspose.Email.Mail;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using Aspose.Email.Calendar;
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


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Mail;


void SavingTheCalendarItemAsMSG()
{
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiCalendar> calendar = System::MakeObject<MapiCalendar>(L"LAKE ARGYLE WA 6743", L"Appointment", L"This is a very important meeting :)", System::DateTime(2012, 10, 2, 13, 0, 0), System::DateTime(2012, 10, 2, 14, 0, 0));
    
    // ExStart:SavingTheCalendarItemAsMSG
    calendar->Save(dataDir + L"CalendarItemAsMSG_out.Msg", Aspose::Email::Mail::AppointmentSaveFormat::Msg);
    // ExEnd:SavingTheCalendarItemAsMSG
}







