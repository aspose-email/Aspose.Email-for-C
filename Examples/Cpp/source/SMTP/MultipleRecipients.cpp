#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/diagnostics/trace.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;


static System::SharedPtr<Aspose::Email::Clients::Smtp::SmtpClient> GetSmtpClient()
{
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"your.email@gmail.com", u"your.password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);

    return client;
}


void MultipleRecipients()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    System::String dstEmail = dataDir + u"outputAttachments.msg";
    
    // Declare msg as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Use MailMessage properties like specify sender, recipient and message
    
    // Specify the recipients mail addresses
    message->get_To()->Add(u"receiver1@receiver.com");
    message->get_To()->Add(u"receiver2@receiver.com");
    message->get_To()->Add(u"receiver3@receiver.com");
    message->get_To()->Add(u"receiver4@receiver.com");
    
    message->get_CC()->Add(u"CC1@receiver.com");
    message->get_CC()->Add(u"CC2@receiver.com");
    
    message->get_Bcc()->Add(u"Bcc1@receiver.com");
    message->get_Bcc()->Add(u"Bcc2@receiver.com");
    
    message->set_From(u"newcustomeronnet@gmail.com");
    message->set_Subject(u"Test Email");
    message->set_Body(u"Hello World!");
    
    
    // Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = GetSmtpClient();
    
    try
    {
        // Client will send this message
        client->Send(message);
        // Show only if message sent successfully
        System::Console::WriteLine(u"Message sent");
    }
    catch (System::Exception& ex)
    {
        System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
    }
    
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Email sent to multiple recipients successfully.");
}


