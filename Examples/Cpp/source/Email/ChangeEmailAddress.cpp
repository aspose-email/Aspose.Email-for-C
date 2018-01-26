//using Aspose.Email.Clients.Smtp;
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
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ChangeEmailAddress()
{
    // ExStart:ChangeEmailAddress
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + L"test.eml");
    
    // A To address with a friendly name can also be specified like this
    message->get_To()->Add(System::MakeObject<MailAddress>(L"kyle@to.com", System::String(L"Kyle Huang")));
    
    // Specify Cc and Bcc email address along with a friendly name
    message->get_CC()->Add(System::MakeObject<MailAddress>(L"guangzhou@cc.com", System::String(L"Guangzhou Team")));
    message->get_Bcc()->Add(System::MakeObject<MailAddress>(L"ahaq@bcc.com", System::String(L"Ammad ulHaq ")));
    
    message->Save(dataDir + L"MessageWithFrienlyName_out.eml", SaveOptions::get_DefaultEml());
    // ExEnd:ChangeEmailAddress
}






