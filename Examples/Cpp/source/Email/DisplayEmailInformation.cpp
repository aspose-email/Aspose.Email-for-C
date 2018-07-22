#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlLoadOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void DisplayEmailInformation()
{
    // ExStart:DisplayEmailInformation
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create MailMessage instance by loading an Eml file
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"test.eml", System::MakeObject<EmlLoadOptions>());
    
    // Gets the sender info, recipient info, Subject, htmlbody and textbody
    System::Console::Write(u"From:");
    System::Console::WriteLine(message->get_From());
    System::Console::Write(u"To:");
    System::Console::WriteLine(message->get_To());
    System::Console::Write(u"Subject:");
    System::Console::WriteLine(message->get_Subject());
    System::Console::WriteLine(u"HtmlBody:");
    System::Console::WriteLine(message->get_HtmlBody());
    System::Console::WriteLine(u"TextBody");
    System::Console::WriteLine(message->get_Body());
    // ExEnd:DisplayEmailInformation
}






