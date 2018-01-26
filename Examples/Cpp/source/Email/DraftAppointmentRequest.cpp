#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Mail/MimeParts/AlternateView.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Appointments/AppointmentMethodType.h>
#include <Formats/Appointments/Appointment.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void DraftAppointmentRequest()
{
    // ExStart:DraftAppointmentRequest
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstDraft = dataDir + L"appointment-draft_out.msg";
    
    System::String sender = L"test@gmail.com";
    System::String recipient = L"test@email.com";
    
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(sender, recipient, System::String::Empty, System::String::Empty);
    
    System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(System::String::Empty, System::DateTime::get_Now(), System::DateTime::get_Now(), MailAddress::to_MailAddress(sender), MailAddressCollection::to_MailAddressCollection(recipient));
    app->set_Method(Aspose::Email::Mail::AppointmentMethodType::Publish);
    
    message->AddAlternateView(app->RequestApointment());
    
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(message);
    
    // Save the appointment as draft.
    msg->Save(dstDraft);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Draft saved at " + dstDraft);
    // ExEnd:DraftAppointmentRequest
}






