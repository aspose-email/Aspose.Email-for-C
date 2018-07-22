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
#include <system/date_time.h>
#include <Mapi/MapiMessageFlags.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/FollowUpManager.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void SetFollowUpForRecipients()
{
    // ExStart:SetFollowUpForRecipients
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    mailMsg->set_Sender(u"AETest12@gmail.com");
    mailMsg->set_To(u"receiver@gmail.com");
    mailMsg->set_Body(u"This message will test if follow up options can be added to a new mapi message.");
    
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(mailMsg);
    mapi->SetMessageFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_UNSENT);
    // Mark this message as draft
    
    System::DateTime dtReminderDate(2013, 5, 23, 16, 40, 0);
    
    // Add the follow up flag for receipient now
    FollowUpManager::SetFlagForRecipients(mapi, u"Follow up", dtReminderDate);
    mapi->Save(dataDir + u"SetFollowUpForRecipients_out.msg");
    // ExEnd:SetFollowUpForRecipients
}

