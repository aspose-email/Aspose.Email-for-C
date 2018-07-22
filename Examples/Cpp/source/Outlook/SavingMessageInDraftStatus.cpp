/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/setters_wrap.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <MsgLoadOptions.h>
#include <Mapi/MapiMessageFlags.h>
#include <Mapi/MapiMessage.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void SavingMessageInDraftStatus()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:SavingMessageInDraftStatus
    // Change properties of an existing MSG file
    System::String strExistingMsg = u"message.msg";
    
    // Load the existing file in MailMessage and Change the properties
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + strExistingMsg, System::MakeObject<MsgLoadOptions>());
    System::setter_add_wrap(msg.GetPointer(), &MailMessage::get_Subject, &MailMessage::set_Subject, u"NEW SUBJECT (updated by Aspose.Email)");
    System::setter_add_wrap(msg.GetPointer(), &MailMessage::get_HtmlBody, &MailMessage::set_HtmlBody, u"NEW BODY (udpated by Aspose.Email)");
    
    // Create an instance of type MapiMessage from MailMessage, Set message flag to un-sent (draft status) and Save it
    System::SharedPtr<MapiMessage> mapiMsg = MapiMessage::FromMailMessage(msg);
    mapiMsg->SetMessageFlags(Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_UNSENT);
    mapiMsg->Save(dataDir + u"SavingMessageInDraftStatus_out.msg");
    // ExEnd:SavingMessageInDraftStatus
}

