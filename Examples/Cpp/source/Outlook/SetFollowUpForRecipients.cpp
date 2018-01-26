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
#include <system/date_time.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void SetFollowUpForRecipients()
{
    // ExStart:SetFollowUpForRecipients
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    mailMsg->set_Sender(L"AETest12@gmail.com");
    mailMsg->set_To(L"receiver@gmail.com");
    mailMsg->set_Body(L"This message will test if follow up options can be added to a new mapi message.");
    
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(mailMsg);
    mapi->SetMessageFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT);
    // Mark this message as draft
    
    System::DateTime dtReminderDate(2013, 5, 23, 16, 40, 0);
    
    // Add the follow up flag for receipient now
    FollowUpManager::SetFlagForRecipients(mapi, L"Follow up", dtReminderDate);
    mapi->Save(dataDir + L"SetFollowUpForRecipients_out.msg");
    // ExEnd:SetFollowUpForRecipients
}







