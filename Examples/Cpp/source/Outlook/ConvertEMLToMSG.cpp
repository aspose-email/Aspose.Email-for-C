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
#include <MailMessage.h>
#include <EmlLoadOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void ConvertEMLToMSG()
{
    //ExStart:ConvertEMLToMSG
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load mail message
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"Message.eml", System::MakeObject<EmlLoadOptions>());
    // Save as MSG
    message->Save(dataDir + u"ConvertEMLToMSG_out.msg", SaveOptions::get_DefaultMsgUnicode());
    //ExEnd:ConvertEMLToMSG
}

