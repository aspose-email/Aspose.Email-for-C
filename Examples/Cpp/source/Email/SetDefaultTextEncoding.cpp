/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void SetDefaultTextEncoding()
{
    // ExStart:SetDefaultTextEncoding           
    // Create an instance of MailMessage
    System::String fileName = GetDataDir_Email();
    System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
    
    // Set the default or preferred encoding. This encoding will be used as the default for the from/to email addresses, subject and body of message.
    msg->set_PreferredTextEncoding(System::Text::Encoding::GetEncoding(28591));
    
    // Set email addresses, subject and body
    msg->set_From(System::MakeObject<MailAddress>(L"dmo@domain.com", System::String(L"démo")));
    msg->get_To()->Add(System::MakeObject<MailAddress>(L"dmo@domain.com", System::String(L"démo")));
    msg->set_Subject(L"démo");
    msg->set_HtmlBody(L"démo");
    msg->Save(fileName + L"SetDefaultTextEncoding_out.msg", SaveOptions::get_DefaultMsg());
    // ExEnd:SetDefaultTextEncoding
}






