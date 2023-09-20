﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <MsgLoadOptions.h>
#include <MhtmlLoadOptions.h>
#include <MailMessage.h>
#include <HtmlLoadOptions.h>
#include <EmlLoadOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void LoadMessageWithLoadOptions()
{
    // ExStart:LoadMessageWithLoadOptions
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Load Eml, html, mhtml, msg and dat file 
    System::SharedPtr<MailMessage> mailMessage = MailMessage::Load(dataDir + u"Message.eml", System::MakeObject<EmlLoadOptions>());
    MailMessage::Load(dataDir + u"description.html", System::MakeObject<HtmlLoadOptions>());
    MailMessage::Load(dataDir + u"Message.mhtml", System::MakeObject<MhtmlLoadOptions>());
    MailMessage::Load(dataDir + u"Message.msg", System::MakeObject<MsgLoadOptions>());
    
    // loading with custom options
    System::SharedPtr<EmlLoadOptions> emlLoadOptions = System::MakeObject<EmlLoadOptions>();
    //emlLoadOptions->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8()); 
    emlLoadOptions->set_PreserveTnefAttachments(true);

    MailMessage::Load(dataDir + u"description.html", emlLoadOptions);
    System::SharedPtr<HtmlLoadOptions> htmlLoadOptions = System::MakeObject<HtmlLoadOptions>();
    //htmlLoadOptions->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8()); 
    htmlLoadOptions->set_ShouldAddPlainTextView(true); 
    htmlLoadOptions->set_PathToResources(dataDir);

        //[&]{ auto tmp_1 = System::MakeObject<HtmlLoadOptions>(); tmp_1->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8()); tmp_1->set_ShouldAddPlainTextView(true); tmp_1->set_PathToResources(dataDir); return tmp_1; }();
    MailMessage::Load(dataDir + u"description.html", emlLoadOptions);
    // ExEnd:LoadMessageWithLoadOptions
}






