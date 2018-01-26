#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Mail;


void CreateSaveOutlookFiles()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + L"message.msg";
    
    // Create an instance of MailMessage class
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    
    // Set FROM field of the message
    mailMsg->set_From(L"from@domain.com");
    
    // Set TO field of the message
    mailMsg->get_To()->Add(L"to@domain.com");
    
    // Set SUBJECT of the message
    mailMsg->set_Subject(L"creating an outlook message file");
    
    // Set BODY of the message
    mailMsg->set_Body(L"This message is created by Aspose.Email");
    
    // Create an instance of MapiMessage class and pass MailMessage as argument
    System::SharedPtr<MapiMessage> outlookMsg = MapiMessage::FromMailMessage(mailMsg);
    
    // Save the message (msg) file
    outlookMsg->Save(dst);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + L"MSG saved successfully at " + dst);
}







