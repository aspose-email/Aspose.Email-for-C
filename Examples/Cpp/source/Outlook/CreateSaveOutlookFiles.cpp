#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/console.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void CreateSaveOutlookFiles()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"message.msg";
    
    // Create an instance of MailMessage class
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    
    // Set FROM field of the message
    mailMsg->set_From(u"from@domain.com");
    
    // Set TO field of the message
    mailMsg->get_To()->Add(u"to@domain.com");
    
    // Set SUBJECT of the message
    mailMsg->set_Subject(u"creating an outlook message file");
    
    // Set BODY of the message
    mailMsg->set_Body(u"This message is created by Aspose.Email");
    
    // Create an instance of MapiMessage class and pass MailMessage as argument
    System::SharedPtr<MapiMessage> outlookMsg = MapiMessage::FromMailMessage(mailMsg);
    
    // Save the message (msg) file
    outlookMsg->Save(dst);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"MSG saved successfully at " + dst);
}

