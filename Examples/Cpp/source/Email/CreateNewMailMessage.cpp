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
#include <MsgSaveOptions.h>
#include <MhtSaveOptions.h>
#include <MailMessageSaveType.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlSaveOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void CreateNewMailMessage()
{
    // ExStart:CreateNewMailMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set subject of the message, Html body and sender information
    message->set_Subject(u"New message created by Aspose.Email for .NET");
    message->set_HtmlBody(System::String(u"<b>This line is in bold.</b> <br/> <br/>") + u"<font color=blue>This line is in blue color</font>");
    message->set_From(System::MakeObject<MailAddress>(u"from@domain.com", u"Sender Name", false));
    
    // Add TO recipients and Add CC recipients
    message->get_To()->Add(System::MakeObject<MailAddress>(u"to1@domain.com", u"Recipient 1", false));
    message->get_To()->Add(System::MakeObject<MailAddress>(u"to2@domain.com", u"Recipient 2", false));
    message->get_CC()->Add(System::MakeObject<MailAddress>(u"cc1@domain.com", u"Recipient 3", false));
    message->get_CC()->Add(System::MakeObject<MailAddress>(u"cc2@domain.com", u"Recipient 4", false));
    
    // Save message in EML, EMLX, MSG and MHTML formats
    message->Save(dataDir + u"CreateNewMailMessage_out.eml", SaveOptions::get_DefaultEml());
    message->Save(dataDir + u"CreateNewMailMessage_out.emlx", SaveOptions::CreateSaveOptions(MailMessageSaveType::get_EmlxFormat()));
    message->Save(dataDir + u"CreateNewMailMessage_out.msg", SaveOptions::get_DefaultMsgUnicode());
    message->Save(dataDir + u"CreateNewMailMessage_out.mhtml", SaveOptions::get_DefaultMhtml());
    // ExEnd:CreateNewMailMessage
}






