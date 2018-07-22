/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <MsgLoadOptions.h>
#include <Mapi/MapiMessageFlags.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadAndWritingOutlookTemplateFile()
{
    //ExStart:ReadAndWritingOutlookTemplateFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook template (OFT) file in MailMessage's instance
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"sample.oft", System::MakeObject<MsgLoadOptions>());
    
    // Set the sender and recipients information
    System::String senderDisplayName = u"John";
    System::String senderEmailAddress = u"john@abc.com";
    System::String recipientDisplayName = u"William";
    System::String recipientEmailAddress = u"william@xzy.com";
    
    message->set_Sender(System::MakeObject<MailAddress>(senderEmailAddress, senderDisplayName));
    message->get_To()->Add(System::MakeObject<MailAddress>(recipientEmailAddress, recipientDisplayName));
    message->set_HtmlBody(message->get_HtmlBody().Replace(u"DisplayName", System::String(u"<b>") + recipientDisplayName + u"</b>"));
    
    // Set the name, location and time in email body
    System::String meetingLocation = System::String(u"<u>") + u"Hall 1, Convention Center, New York, USA" + u"</u>";
    System::String meetingTime = System::String(u"<u>") + u"Monday, June 28, 2010" + u"</u>";
    message->set_HtmlBody(message->get_HtmlBody().Replace(u"MeetingPlace", meetingLocation));
    message->set_HtmlBody(message->get_HtmlBody().Replace(u"MeetingTime", meetingTime));
    
    // Save the message in MSG format and open in Office Outlook
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(message);
    msg->SetMessageFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_UNSENT);
    msg->Save(dataDir + u"ReadAndWritingOutlookTemplateFile_out.msg");
    //ExEnd:ReadAndWritingOutlookTemplateFile
}

