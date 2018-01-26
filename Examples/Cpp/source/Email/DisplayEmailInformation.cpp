#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/EmlLoadOptions.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void DisplayEmailInformation()
{
    // ExStart:DisplayEmailInformation
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create MailMessage instance by loading an Eml file
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + L"test.eml", System::MakeObject<EmlLoadOptions>());
    
    // Gets the sender info, recipient info, Subject, htmlbody and textbody
    System::Console::Write(L"From:");
    System::Console::WriteLine(message->get_From());
    System::Console::Write(L"To:");
    System::Console::WriteLine(message->get_To());
    System::Console::Write(L"Subject:");
    System::Console::WriteLine(message->get_Subject());
    System::Console::WriteLine(L"HtmlBody:");
    System::Console::WriteLine(message->get_HtmlBody());
    System::Console::WriteLine(L"TextBody");
    System::Console::WriteLine(message->get_Body());
    // ExEnd:DisplayEmailInformation
}






