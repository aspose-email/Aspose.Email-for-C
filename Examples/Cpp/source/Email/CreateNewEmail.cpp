#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/console.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MhtSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void CreateNewEmail()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set subject of the message
    message->set_Subject(L"New message created by Aspose.Email for .NET");
    
    // Set Html body
    message->set_IsBodyHtml(true);
    message->set_HtmlBody(L"<b>This line is in bold.</b> <br/> <br/><font color=blue>This line is in blue color</font>");
    
    // Set sender information
    message->set_From(L"from@domain.com");
    
    // Add TO recipients
    message->get_To()->Add(L"to1@domain.com");
    message->get_To()->Add(L"to2@domain.com");
    
    // Add CC recipients
    message->get_CC()->Add(L"cc1@domain.com");
    message->get_CC()->Add(L"cc2@domain.com");
    
    // Save message in EML, MSG and MHTML formats
    message->Save(dataDir + L"CreateNewEmail_out.eml", SaveOptions::get_DefaultEml());
    
    message->Save(dataDir + L"CreateNewEmail_out.msg", SaveOptions::get_DefaultMsgUnicode());
    
    message->Save(dataDir + L"CreateNewEmail_out.mhtml", SaveOptions::get_DefaultMhtml());
    
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Created new email in EML, MSG and MHTML formats successfully.");
}






