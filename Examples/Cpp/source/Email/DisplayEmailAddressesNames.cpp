#include <system/shared_ptr.h>
#include <system/object.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>


using namespace Aspose::Email;

void DisplayEmailAddressesNames()
{
    // ExStart:DisplayEmailAddressesNames
    // Declare message as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"Sender <sender@from.com>", u"Recipient <recipient@to.com>");
    
    // Specify the recipients mail addresses
    message->get_To()->Add(u"receiver1@receiver.com");
    message->get_To()->Add(u"receiver2@receiver.com");
    message->get_To()->Add(u"receiver3@receiver.com");
    message->get_To()->Add(u"receiver4@receiver.com");
    
    // Specifying CC and BCC Addresses
    message->get_CC()->Add(u"CC1@receiver.com");
    message->get_CC()->Add(u"CC2@receiver.com");
    message->get_Bcc()->Add(u"Bcc1@receiver.com");
    message->get_Bcc()->Add(u"Bcc2@receiver.com");
    // ExEnd:DisplayEmailAddressesNames
}






