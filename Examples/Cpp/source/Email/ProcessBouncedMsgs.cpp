#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/environment.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/Bounce/DSNAction.h>
#include <Mail/Bounce/BounceResult.h>

#include "Examples.h"


using namespace Aspose::Email::Mail::Bounce;
using namespace Aspose::Email::Mail;


void ProcessBouncedMsgs()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + L"test.eml";
    
    System::String fileName = dstEmail;
    System::SharedPtr<MailMessage> mail = MailMessage::Load(fileName);
    System::SharedPtr<BounceResult> result = mail->CheckBounced();
    System::Console::WriteLine(fileName);
    System::Console::WriteLine(System::String(L"IsBounced : ") + result->get_IsBounced());
    System::Console::WriteLine(System::String(L"Action : ") + System::ObjectExt::ToString(result->get_Action()));
    System::Console::WriteLine(System::String(L"Recipient : ") + result->get_Recipient());
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Bounce information displayed successfully.");
}






