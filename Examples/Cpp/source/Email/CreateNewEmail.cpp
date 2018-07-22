#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MhtSaveOptions.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlSaveOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void CreateNewEmail()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set subject of the message
    message->set_Subject(u"New message created by Aspose.Email for .NET");
    
    // Set Html body
    message->set_IsBodyHtml(true);
    message->set_HtmlBody(u"<b>This line is in bold.</b> <br/> <br/><font color=blue>This line is in blue color</font>");
    
    // Set sender information
    message->set_From(u"from@domain.com");
    
    // Add TO recipients
    message->get_To()->Add(u"to1@domain.com");
    message->get_To()->Add(u"to2@domain.com");
    
    // Add CC recipients
    message->get_CC()->Add(u"cc1@domain.com");
    message->get_CC()->Add(u"cc2@domain.com");
    
    // Save message in EML, MSG and MHTML formats
    message->Save(dataDir + u"CreateNewEmail_out.eml", Aspose::Email::SaveOptions::get_DefaultEml());
    
    message->Save(dataDir + u"CreateNewEmail_out.msg", Aspose::Email::SaveOptions::get_DefaultMsgUnicode());
    
    message->Save(dataDir + u"CreateNewEmail_out.mhtml", Aspose::Email::SaveOptions::get_DefaultMhtml());
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Created new email in EML, MSG and MHTML formats successfully.");
}






