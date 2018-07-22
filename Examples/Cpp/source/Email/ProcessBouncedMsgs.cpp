#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/environment.h>
#include <system/console.h>
#include <MailMessage.h>
#include <Bounce/DSNAction.h>
#include <Bounce/BounceResult.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Bounce;

void ProcessBouncedMsgs()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + u"test.eml";
    
    System::String fileName = dstEmail;
    System::SharedPtr<MailMessage> mail = MailMessage::Load(fileName);
    System::SharedPtr<BounceResult> result = mail->CheckBounced();
    System::Console::WriteLine(fileName);
    System::Console::WriteLine(System::String(u"IsBounced : ") + result->get_IsBounced());
    System::Console::WriteLine(System::String(u"Action : ") + System::ObjectExt::ToString(result->get_Action()));
    System::Console::WriteLine(System::String(u"Recipient : ") + result->get_Recipient());
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Bounce information displayed successfully.");
}






