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
#include <system/exceptions.h>
#include <system/date_time.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiCalendar.h>
#include <Mapi/IMapiMessageItem.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Calendar/AppointmentSaveFormat.h>
#include <Calendar/Appointment.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email;


using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Calendar;

void AddDisplayReminderToACalendar()
{
    // ExStart:AddDisplayReminderToACalendar
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create Appointment 
    System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(u"Home", System::DateTime::get_Now().AddHours(1), System::DateTime::get_Now().AddHours(1), MailAddress::to_MailAddress(u"organizer@domain.com"), MailAddressCollection::to_MailAddressCollection(u"attendee@gmail.com"));
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    msg->AddAlternateView(app->RequestApointment());
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(msg);
    System::SharedPtr<MapiCalendar> calendar = System::ExplicitCast<Aspose::Email::Mapi::MapiCalendar>(mapi->ToMapiMessageItem());
    
    // Set calendar Properties 
    calendar->set_ReminderSet(true);
    calendar->set_ReminderDelta(45);
    //45 min before start of event
    
    System::String savedFile = (dataDir + u"calendarWithDisplayReminder.ics");
    calendar->Save(savedFile, Aspose::Email::Calendar::AppointmentSaveFormat::Ics);
    // ExEnd:AddDisplayReminderToACalendar
}

