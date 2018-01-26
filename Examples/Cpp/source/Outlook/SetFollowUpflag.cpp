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
#include <system/date_time.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/FollowUpOptions.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Mail;


void SetFollowUpflag()
{
    //ExStart:SetFollowUpflag
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    mailMsg->set_Sender(L"AETest12@gmail.com");
    mailMsg->set_To(L"receiver@gmail.com");
    mailMsg->set_Body(L"This message will test if follow up options can be added to a new mapi message.");
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(mailMsg);
    
    System::DateTime dtStartDate(2013, 5, 23, 14, 40, 0);
    System::DateTime dtReminderDate(2013, 5, 23, 16, 40, 0);
    System::DateTime dtDueDate = dtReminderDate.AddDays(1);
    
    System::SharedPtr<FollowUpOptions> options = System::MakeObject<FollowUpOptions>(L"Follow Up", dtStartDate, dtDueDate, dtReminderDate);
    FollowUpManager::SetOptions(mapi, options);
    mapi->Save(dataDir + L"SetFollowUpflag_out.msg");
    //ExEnd:SetFollowUpflag
}







