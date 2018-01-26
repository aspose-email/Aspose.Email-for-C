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
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/EmlLoadOptions.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ConvertEMLToMSG()
{
    //ExStart:ConvertEMLToMSG
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load mail message
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + L"Message.eml", System::MakeObject<EmlLoadOptions>());
    // Save as MSG
    message->Save(dataDir + L"ConvertEMLToMSG_out.msg", SaveOptions::get_DefaultMsgUnicode());
    //ExEnd:ConvertEMLToMSG
}







