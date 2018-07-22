#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Calendar/AppointmentMethodType.h>
#include <Calendar/Appointment.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Calendar;

void DraftAppointmentRequest()
{
    // ExStart:DraftAppointmentRequest
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstDraft = dataDir + u"appointment-draft_out.msg";
    
    System::String sender = u"test@gmail.com";
    System::String recipient = u"test@email.com";
    
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(sender, recipient, System::String::Empty, System::String::Empty);
    
    System::SharedPtr<Appointment> app = [&]{ auto tmp_0 = System::MakeObject<Appointment>(System::String::Empty, System::DateTime::get_Now(), System::DateTime::get_Now(), MailAddress::to_MailAddress(sender), MailAddressCollection::to_MailAddressCollection(recipient)); tmp_0->set_MethodType(Aspose::Email::Calendar::AppointmentMethodType::Publish); return tmp_0; }();
    
    message->AddAlternateView(app->RequestApointment());
    
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(message);
    
    // Save the appointment as draft.
    msg->Save(dstDraft);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Draft saved at " + dstDraft);
    // ExEnd:DraftAppointmentRequest
}






