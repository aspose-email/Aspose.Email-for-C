/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/MsgLoadOptions.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void ReadAndWritingOutlookTemplateFile()
{
    //ExStart:ReadAndWritingOutlookTemplateFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook template (OFT) file in MailMessage's instance
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + L"sample.oft", System::MakeObject<MsgLoadOptions>());
    
    // Set the sender and recipients information
    System::String senderDisplayName = L"John";
    System::String senderEmailAddress = L"john@abc.com";
    System::String recipientDisplayName = L"William";
    System::String recipientEmailAddress = L"william@xzy.com";
    
    message->set_Sender(System::MakeObject<MailAddress>(senderEmailAddress, senderDisplayName));
    message->get_To()->Add(System::MakeObject<MailAddress>(recipientEmailAddress, recipientDisplayName));
    message->set_HtmlBody(message->get_HtmlBody().Replace(L"DisplayName", System::String(L"<b>") + recipientDisplayName + L"</b>"));
    
    // Set the name, location and time in email body
    System::String meetingLocation = System::String(L"<u>") + L"Hall 1, Convention Center, New York, USA" + L"</u>";
    System::String meetingTime = System::String(L"<u>") + L"Monday, June 28, 2010" + L"</u>";
    message->set_HtmlBody(message->get_HtmlBody().Replace(L"MeetingPlace", meetingLocation));
    message->set_HtmlBody(message->get_HtmlBody().Replace(L"MeetingTime", meetingTime));
    
    // Save the message in MSG format and open in Office Outlook
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(message);
    msg->SetMessageFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT);
    msg->Save(dataDir + L"ReadAndWritingOutlookTemplateFile_out.msg");
    //ExEnd:ReadAndWritingOutlookTemplateFile
}







