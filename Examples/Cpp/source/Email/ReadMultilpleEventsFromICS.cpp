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
#include <system/collections/list.h>
#include <Calendar/CalendarReader.h>
#include <Calendar/Appointment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;

void ReadMultilpleEventsFromICS()
{
    //ExStart: ReadMultilpleEventsFromICS
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Appointment>>> appointments = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<Appointment>>>();
    
    System::SharedPtr<CalendarReader> reader = System::MakeObject<CalendarReader>(dataDir + u"US-Holidays.ics");
    
    while (reader->NextEvent())
    {
        appointments->Add(reader->get_Current());
    }
    //working with appointments...
    
    //ExEnd: ReadMultilpleEventsFromICS
}






