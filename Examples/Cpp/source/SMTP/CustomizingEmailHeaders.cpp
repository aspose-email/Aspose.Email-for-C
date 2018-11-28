#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/environment.h>
#include <system/date_time.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <Mime/HeaderCollection.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email::Mime;
using namespace Aspose::Email;

void CustomizingEmailHeaders()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_SMTP();
    System::String dstEmail = dataDir + u"MsgHeaders.msg";
    
    // Create an instance MailMessage class
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Specify ReplyTo
    msg->get_ReplyToList()->Add(u"reply@reply.com");
    
    // From field
    msg->set_From(u"sender@sender.com");
    
    // To field
    msg->get_To()->Add(u"receiver1@receiver.com");
    
    // Adding Cc and Bcc Addresses
    msg->get_CC()->Add(u"receiver2@receiver.com");
    msg->get_Bcc()->Add(u"receiver3@receiver.com");
    
    // Message subject
    msg->set_Subject(u"test mail");
    
    // Specify Date
    msg->set_Date(System::DateTime(2006, 3, 6));
    
    // Specify XMailer
    msg->set_XMailer(u"Aspose.Email");
    
    // Specify Secret Header
    msg->get_Headers()->Add(u"secret-header", u"mystery");
    
    // Save message to disc
    msg->Save(dstEmail, SaveOptions::get_DefaultMsgUnicode());
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Message saved with customized headers successfully at " + dstEmail);
}

