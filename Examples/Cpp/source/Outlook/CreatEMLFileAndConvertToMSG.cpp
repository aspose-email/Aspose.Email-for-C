//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using Aspose.Email;
//using Aspose.Email.Examples.CSharp.Email;
//using Aspose.Email.Outlook;
//using Aspose.Email.Outlook.Pst;
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
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void CreatEMLFileAndConvertToMSG()
{
    // ExStart:CreatEMLFileAndConvertToMSG
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create new message and save as EML
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(L"from@domain.com", L"to@domain.com");
    message->set_Subject(L"subject of email");
    message->set_HtmlBody(System::String(L"<b>Eml to msg conversion using Aspose.Email</b>") + L"<br><hr><br><font color=blue>This is a test eml file which will be converted to msg format.</font>");
    // Add attachments
    message->get_Attachments()->Add(System::MakeObject<Attachment>(dataDir + L"attachment_1.doc"));
    message->get_Attachments()->Add(System::MakeObject<Attachment>(dataDir + L"download.png"));
    
    // Save it EML
    message->Save(dataDir + L"CreatEMLFileAndConvertToMSG_out.eml", SaveOptions::get_DefaultEml());
    // Save it to MSG
    message->Save(dataDir + L"CreatEMLFileAndConvertToMSG_out.msg", SaveOptions::get_DefaultMsgUnicode());
    // ExEnd:CreatEMLFileAndConvertToMSG
}







