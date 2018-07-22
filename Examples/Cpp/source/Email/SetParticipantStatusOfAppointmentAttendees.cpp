#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <ParticipationStatus.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Calendar/Appointment.h>


using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;

void SetParticipantStatusOfAppointmentAttendees()
{
    //ExStart: SetParticipantStatusOfAppointmentAttendees
    System::String location = u"Room 5";
    System::DateTime startDate(2011, 12, 10, 10, 12, 11), endDate(2012, 11, 13, 13, 11, 12);
    System::SharedPtr<MailAddress> organizer = System::MakeObject<MailAddress>(u"aaa@amail.com", System::String(u"Organizer"));
    System::SharedPtr<MailAddressCollection> attendees = System::MakeObject<MailAddressCollection>();
    System::SharedPtr<MailAddress> attendee1 = System::MakeObject<MailAddress>(u"bbb@bmail.com", System::String(u"First attendee"));
    System::SharedPtr<MailAddress> attendee2 = System::MakeObject<MailAddress>(u"ccc@cmail.com", System::String(u"Second attendee"));
    
    attendee1->set_ParticipationStatus(Aspose::Email::ParticipationStatus::Accepted);
    attendee2->set_ParticipationStatus(Aspose::Email::ParticipationStatus::Declined);
    attendees->Add(attendee1);
    attendees->Add(attendee2);
    
    System::SharedPtr<Appointment> target = System::MakeObject<Appointment>(location, startDate, endDate, organizer, attendees);
    //ExEnd: SetParticipantStatusOfAppointmentAttendees
}



