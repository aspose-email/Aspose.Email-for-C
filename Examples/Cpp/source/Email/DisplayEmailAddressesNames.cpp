#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>


using namespace Aspose::Email::Mail;


void DisplayEmailAddressesNames()
{
    // ExStart:DisplayEmailAddressesNames
    // Declare message as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(L"Sender <sender@from.com>", L"Recipient <recipient@to.com>");
    
    // Specify the recipients mail addresses
    message->get_To()->Add(L"receiver1@receiver.com");
    message->get_To()->Add(L"receiver2@receiver.com");
    message->get_To()->Add(L"receiver3@receiver.com");
    message->get_To()->Add(L"receiver4@receiver.com");
    
    // Specifying CC and BCC Addresses
    message->get_CC()->Add(L"CC1@receiver.com");
    message->get_CC()->Add(L"CC2@receiver.com");
    message->get_Bcc()->Add(L"Bcc1@receiver.com");
    message->get_Bcc()->Add(L"Bcc2@receiver.com");
    // ExEnd:DisplayEmailAddressesNames
}






