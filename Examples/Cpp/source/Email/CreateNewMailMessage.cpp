/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mail/TemplateMerge/MailMessageSaveType.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MhtSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void CreateNewMailMessage()
{
    // ExStart:CreateNewMailMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create a new instance of MailMessage class
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Set subject of the message, Html body and sender information
    message->set_Subject(L"New message created by Aspose.Email for .NET");
    message->set_HtmlBody(System::String(L"<b>This line is in bold.</b> <br/> <br/>") + L"<font color=blue>This line is in blue color</font>");
    message->set_From(System::MakeObject<MailAddress>(L"from@domain.com", L"Sender Name", false));
    
    // Add TO recipients and Add CC recipients
    message->get_To()->Add(System::MakeObject<MailAddress>(L"to1@domain.com", L"Recipient 1", false));
    message->get_To()->Add(System::MakeObject<MailAddress>(L"to2@domain.com", L"Recipient 2", false));
    message->get_CC()->Add(System::MakeObject<MailAddress>(L"cc1@domain.com", L"Recipient 3", false));
    message->get_CC()->Add(System::MakeObject<MailAddress>(L"cc2@domain.com", L"Recipient 4", false));
    
    // Save message in EML, EMLX, MSG and MHTML formats
    message->Save(dataDir + L"CreateNewMailMessage_out.eml", SaveOptions::get_DefaultEml());
    message->Save(dataDir + L"CreateNewMailMessage_out.emlx", SaveOptions::CreateSaveOptions(MailMessageSaveType::get_EmlxFormat()));
    message->Save(dataDir + L"CreateNewMailMessage_out.msg", SaveOptions::get_DefaultMsgUnicode());
    message->Save(dataDir + L"CreateNewMailMessage_out.mhtml", SaveOptions::get_DefaultMhtml());
    // ExEnd:CreateNewMailMessage
}






