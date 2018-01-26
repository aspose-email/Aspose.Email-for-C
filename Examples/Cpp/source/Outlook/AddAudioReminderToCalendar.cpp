//using Aspose.Email.Outlook;
//using Aspose.Email.Mail;
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
#include <system/exceptions.h>
#include <system/date_time.h>
#include <Mail/MimeParts/AlternateView.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>
#include <Formats/Outlook/IMapiMessageItem.h>
#include <Formats/Appointments/AppointmentSaveFormat.h>
#include <Formats/Appointments/Appointment.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void AddAudioReminderToCalendar()
{
    // ExStart:AddAudioReminderToCalendar
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(L"Home", System::DateTime::get_Now().AddHours(1), System::DateTime::get_Now().AddHours(1), MailAddress::to_MailAddress(L"organizer@domain.com"), MailAddressCollection::to_MailAddressCollection(L"attendee@gmail.com"));
    
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    msg->AddAlternateView(app->RequestApointment());
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(msg);
    System::SharedPtr<MapiCalendar> calendar = System::DynamicCast<Aspose::Email::Outlook::MapiCalendar>(mapi->ToMapiMessageItem());
    
    // Set calendar properties
    calendar->set_ReminderSet(true);
    calendar->set_ReminderDelta(58);
    //58 min before start of event
    calendar->set_ReminderFileParameter(dataDir + L"Alarm01.wav");
    System::String savedFile = (dataDir + L"calendarWithAudioReminder_out.ics");
    calendar->Save(savedFile, Aspose::Email::Mail::AppointmentSaveFormat::Ics);
    // ExEnd:AddAudioReminderToCalendar
}







