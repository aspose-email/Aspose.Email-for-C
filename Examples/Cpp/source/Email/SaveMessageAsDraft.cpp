#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/enum_helpers.h>
#include <system/console.h>
#include <Mapi/MapiMessageFlags.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email::Mapi;
using namespace Aspose::Email;

void SaveMessageAsDraft()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + u"New-Draft.msg";
    
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set sender information
    message->set_From(u"from@domain.com");
    
    // Add recipients
    message->get_To()->Add(u"to1@domain.com");
    message->get_To()->Add(u"to2@domain.com");
    
    // Set subject of the message
    message->set_Subject(u"New message created by Aspose.Email");
    
    // Set Html body of the message
    message->set_IsBodyHtml(true);
    message->set_HtmlBody(u"<b>This line is in bold.</b> <br/> <br/><font color=blue>This line is in blue color</font>");
    
    // Create an instance of MapiMessage and load the MailMessag instance into it
    System::SharedPtr<MapiMessage> mapiMsg = MapiMessage::FromMailMessage(message);
    
    // Set the MapiMessageFlags as UNSENT and FROMME
    mapiMsg->SetMessageFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_UNSENT | Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_FROMME);
    
    // Save the MapiMessage to disk
    mapiMsg->Save(dstEmail);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Created draft MSG at " + dstEmail);
}






