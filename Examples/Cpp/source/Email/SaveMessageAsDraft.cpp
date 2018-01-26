#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/enum_helpers.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void SaveMessageAsDraft()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + L"New-Draft.msg";
    
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set sender information
    message->set_From(L"from@domain.com");
    
    // Add recipients
    message->get_To()->Add(L"to1@domain.com");
    message->get_To()->Add(L"to2@domain.com");
    
    // Set subject of the message
    message->set_Subject(L"New message created by Aspose.Email");
    
    // Set Html body of the message
    message->set_IsBodyHtml(true);
    message->set_HtmlBody(L"<b>This line is in bold.</b> <br/> <br/><font color=blue>This line is in blue color</font>");
    
    // Create an instance of MapiMessage and load the MailMessag instance into it
    System::SharedPtr<MapiMessage> mapiMsg = MapiMessage::FromMailMessage(message);
    
    // Set the MapiMessageFlags as UNSENT and FROMME
    mapiMsg->SetMessageFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT | Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_FROMME);
    
    // Save the MapiMessage to disk
    mapiMsg->Save(dstEmail);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Created draft MSG at " + dstEmail);
}






