/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/uri.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Calendar/ReminderTrigger.h>
#include <Calendar/ReminderRelated.h>
#include <Calendar/ReminderDuration.h>
#include <Calendar/ReminderAttendeeCollection.h>
#include <Calendar/ReminderAttendee.h>
#include <Calendar/ReminderAttachmentCollection.h>
#include <Calendar/ReminderAttachment.h>
#include <Calendar/ReminderAction.h>
#include <Calendar/AppointmentReminderCollection.h>
#include <Calendar/AppointmentReminder.h>
#include <Calendar/Appointment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;

void SetReminderByAddingTags()
{
    // ExStart:SetReminderByAddingTags
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::String location = u"Meeting Location: Room 5";
    System::DateTime startDate(1997, 3, 18, 18, 30, 00), endDate(1997, 3, 18, 19, 30, 00);
    System::SharedPtr<MailAddress> organizer = System::MakeObject<MailAddress>(u"aaa@amail.com", System::String(u"Organizer"));
    System::SharedPtr<MailAddressCollection> attendees = System::MakeObject<MailAddressCollection>();
    attendees->Add(System::MakeObject<MailAddress>(u"bbb@bmail.com", System::String(u"First attendee")));
    
    System::SharedPtr<Appointment> target = System::MakeObject<Appointment>(location, startDate, endDate, organizer, attendees);
    
    // Audio alarm that will sound at a precise time and
    // Repeat 4 more times at 15 minute intervals:
    System::SharedPtr<AppointmentReminder> audioReminder = System::MakeObject<AppointmentReminder>();
    audioReminder->set_Trigger(System::MakeObject<ReminderTrigger>(System::DateTime(1997, 3, 17, 13, 30, 0, System::DateTimeKind::Utc)));
    audioReminder->set_Repeat(4);
    audioReminder->set_Duration(System::MakeObject<ReminderDuration>(System::TimeSpan(0, 15, 0)));
    audioReminder->set_Action(Aspose::Email::Calendar::ReminderAction::Audio);
    System::SharedPtr<ReminderAttachment> attach = System::MakeObject<ReminderAttachment>(System::MakeObject<System::Uri>(u"ftp://Host.com/pub/sounds/bell-01.aud"));
    audioReminder->get_Attachments()->Add(attach);
    target->get_Reminders()->Add(audioReminder);
    
    
    // Display alarm that will trigger 30 minutes before the
    // Scheduled start of the event it is
    // Associated with and will repeat 2 more times at 15 minute intervals:
    System::SharedPtr<AppointmentReminder> displayReminder = System::MakeObject<AppointmentReminder>();
    System::SharedPtr<ReminderDuration> dur = System::MakeObject<ReminderDuration>(System::TimeSpan(0, -30, 0));
    displayReminder->set_Trigger(System::MakeObject<ReminderTrigger>(dur, Aspose::Email::Calendar::ReminderRelated::Start));
    displayReminder->set_Repeat(2);
    displayReminder->set_Duration(System::MakeObject<ReminderDuration>(System::TimeSpan(0, 15, 0)));
    displayReminder->set_Action(Aspose::Email::Calendar::ReminderAction::Display);
    displayReminder->set_Description(u"Breakfast meeting with executive team at 8:30 AM EST");
    target->get_Reminders()->Add(displayReminder);
    
    // Email alarm that will trigger 2 days before the
    // Scheduled due date/time. It does not
    // Repeat. The email has a subject, body and attachment link.
    System::SharedPtr<AppointmentReminder> emailReminder = System::MakeObject<AppointmentReminder>();
    System::SharedPtr<ReminderDuration> dur1 = System::MakeObject<ReminderDuration>(System::TimeSpan(-2, 0, 0, 0));
    emailReminder->set_Trigger(System::MakeObject<ReminderTrigger>(dur1, Aspose::Email::Calendar::ReminderRelated::Start));
    System::SharedPtr<ReminderAttendee> attendee = System::MakeObject<ReminderAttendee>(u"john_doe@host.com");
    emailReminder->get_Attendees()->Add(attendee);
    emailReminder->set_Action(Aspose::Email::Calendar::ReminderAction::Email);
    emailReminder->set_Summary(u"REMINDER: SEND AGENDA FOR WEEKLY STAFF MEETING");
    emailReminder->set_Description(u"A draft agenda needs to be sent out to the attendees to the weekly managers meeting (MGR-LIST). Attached is a pointer the document template for the agenda file.");
    System::SharedPtr<ReminderAttachment> attach1 = System::MakeObject<ReminderAttachment>(System::MakeObject<System::Uri>(u"http://Host.com/templates/agenda.doc"));
    emailReminder->get_Attachments()->Add(attach1);
    target->get_Reminders()->Add(emailReminder);
    
    // Procedural alarm that will trigger at a precise date/time
    // And will repeat 23 more times at one hour intervals. The alarm will
    // Invoke a procedure file.
    System::SharedPtr<AppointmentReminder> procReminder = System::MakeObject<AppointmentReminder>();
    procReminder->set_Trigger(System::MakeObject<ReminderTrigger>(System::DateTime(1998, 1, 1, 5, 0, 0, System::DateTimeKind::Utc)));
    procReminder->set_Repeat(23);
    procReminder->set_Duration(System::MakeObject<ReminderDuration>(System::TimeSpan(1, 0, 0)));
    procReminder->set_Action(Aspose::Email::Calendar::ReminderAction::Procedure);
    System::SharedPtr<ReminderAttachment> attach2 = System::MakeObject<ReminderAttachment>(System::MakeObject<System::Uri>(u"ftp://Host.com/novo-procs/felizano.exe"));
    procReminder->get_Attachments()->Add(attach2);
    target->get_Reminders()->Add(procReminder);
    target->Save(dataDir + u"savedFile_out.ics");
    //ExEnd:SetReminderByAddingTags
}

