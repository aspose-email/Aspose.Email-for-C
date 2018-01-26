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
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/MsgLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/MhtmlLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/HtmlLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/EmlLoadOptions.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void LoadMessageWithLoadOptions()
{
    // ExStart:LoadMessageWithLoadOptions
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Load Eml, html, mhtml, msg and dat file 
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + L"Message.eml", System::MakeObject<EmlLoadOptions>());
    MailMessage::Load(dataDir + L"description.html", System::MakeObject<HtmlLoadOptions>());
    MailMessage::Load(dataDir + L"Message.mhtml", System::MakeObject<MhtmlLoadOptions>());
    MailMessage::Load(dataDir + L"Message.msg", System::MakeObject<MsgLoadOptions>());
    
    // loading with custom options
    System::SharedPtr<EmlLoadOptions> emlLoadOptions = [&]{ auto tmp_0 = System::MakeObject<EmlLoadOptions>(); tmp_0->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8()); tmp_0->set_PreserveTnefAttachments(true); return tmp_0; }();
    
    MailMessage::Load(dataDir + L"description.html", emlLoadOptions);
    System::SharedPtr<HtmlLoadOptions> htmlLoadOptions = [&]{ auto tmp_1 = System::MakeObject<HtmlLoadOptions>(); tmp_1->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8()); tmp_1->set_ShouldAddPlainTextView(true); tmp_1->set_PathToResources(dataDir); return tmp_1; }();
    MailMessage::Load(dataDir + L"description.html", emlLoadOptions);
    // ExEnd:LoadMessageWithLoadOptions
}






