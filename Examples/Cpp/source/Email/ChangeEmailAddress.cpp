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
#include <SaveOptions.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlSaveOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void ChangeEmailAddress()
{
    // ExStart:ChangeEmailAddress
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"test.eml");
    
    // A To address with a friendly name can also be specified like this
    message->get_To()->Add(System::MakeObject<MailAddress>(u"kyle@to.com", System::String(u"Kyle Huang")));
    
    // Specify Cc and Bcc email address along with a friendly name
    message->get_CC()->Add(System::MakeObject<MailAddress>(u"guangzhou@cc.com", System::String(u"Guangzhou Team")));
    message->get_Bcc()->Add(System::MakeObject<MailAddress>(u"ahaq@bcc.com", System::String(u"Ammad ulHaq ")));
    
    message->Save(dataDir + u"MessageWithFrienlyName_out.eml", SaveOptions::get_DefaultEml());
    // ExEnd:ChangeEmailAddress
}






