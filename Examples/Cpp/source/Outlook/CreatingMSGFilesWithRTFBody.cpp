//using Aspose.Email.Outlook;
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using Aspose.Email.Mail;
//using System.Text;
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
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void CreatingMSGFilesWithRTFBody()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:CreatingMSGFilesWithRTFBody
    // Create an instance of the MailMessage class
    System::SharedPtr<MailMessage> mailMsg = System::MakeObject<MailMessage>();
    
    // Set from, to, subject and body properties
    mailMsg->set_From(L"from@domain.com");
    mailMsg->set_To(L"to@domain.com");
    mailMsg->set_Subject(L"subject");
    mailMsg->set_HtmlBody(L"<h3>rtf example</h3><p>creating an <b><u>outlook message (msg)</u></b> file using Aspose.Email.</p>");
    
    System::SharedPtr<MapiMessage> outlookMsg = MapiMessage::FromMailMessage(mailMsg);
    outlookMsg->Save(dataDir + L"CreatingMSGFilesWithRTFBody_out.msg");
    // ExEnd:CreatingMSGFilesWithRTFBody
}







