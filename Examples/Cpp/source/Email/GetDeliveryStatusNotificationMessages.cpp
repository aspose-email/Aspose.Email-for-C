//using Aspose.Email.Mail;
//using Aspose.Email.Bounce;
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Mail/Bounce/DSNAction.h>
#include <Mail/Bounce/BounceResult.h>

#include "Examples.h"


using namespace Aspose::Email::Mail::Bounce;
using namespace Aspose::Email::Mail;


void GetDeliveryStatusNotificationMessages()
{
    // ExStart:GetDeliveryStatusNotificationMessages
    System::String fileName = GetDataDir_Email() + L"failed1.msg";
    System::SharedPtr<MailMessage> mail = MailMessage::Load(fileName);
    System::SharedPtr<BounceResult> result = mail->CheckBounced();
    System::Console::WriteLine(fileName);
    System::Console::WriteLine(System::String(L"IsBounced : ") + result->get_IsBounced());
    System::Console::WriteLine(System::String(L"Action : ") + System::ObjectExt::ToString(result->get_Action()));
    System::Console::WriteLine(System::String(L"Recipient : ") + result->get_Recipient());
    System::Console::WriteLine();
    System::Console::WriteLine(System::String(L"Reason : ") + result->get_Reason());
    System::Console::WriteLine(System::String(L"Status : ") + result->get_Status());
    System::Console::WriteLine(System::String(L"OriginalMessage ToAddress 1: ") + result->get_OriginalMessage()->get_To()->idx_get(0)->get_Address());
    System::Console::WriteLine();
    // ExEnd:GetDeliveryStatusNotificationMessages
}






