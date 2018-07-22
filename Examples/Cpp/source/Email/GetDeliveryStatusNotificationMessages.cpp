/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Bounce/DSNAction.h>
#include <Bounce/BounceResult.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Bounce;

void GetDeliveryStatusNotificationMessages()
{
    // ExStart:GetDeliveryStatusNotificationMessages
    System::String fileName = GetDataDir_Email() + u"failed1.msg";
    System::SharedPtr<MailMessage> mail = MailMessage::Load(fileName);
    System::SharedPtr<BounceResult> result = mail->CheckBounced();
    System::Console::WriteLine(fileName);
    System::Console::WriteLine(System::String(u"IsBounced : ") + result->get_IsBounced());
    System::Console::WriteLine(System::String(u"Action : ") + System::ObjectExt::ToString(result->get_Action()));
    System::Console::WriteLine(System::String(u"Recipient : ") + result->get_Recipient());
    System::Console::WriteLine();
    System::Console::WriteLine(System::String(u"Reason : ") + result->get_Reason());
    System::Console::WriteLine(System::String(u"Status : ") + result->get_Status());
    System::Console::WriteLine(System::String(u"OriginalMessage ToAddress 1: ") + result->get_OriginalMessage()->get_To()->idx_get(0)->get_Address());
    System::Console::WriteLine();
    // ExEnd:GetDeliveryStatusNotificationMessages
}






