/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/setters_wrap.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/MsgLoadOptions.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void SavingMessageInDraftStatus()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:SavingMessageInDraftStatus
    // Change properties of an existing MSG file
    System::String strExistingMsg = L"message.msg";
    
    // Load the existing file in MailMessage and Change the properties
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + strExistingMsg, System::MakeObject<MsgLoadOptions>());
    System::setter_add_wrap(msg.get(), &MailMessage::get_Subject, &MailMessage::set_Subject, L"NEW SUBJECT (updated by Aspose.Email)");
    System::setter_add_wrap(msg.get(), &MailMessage::get_HtmlBody, &MailMessage::set_HtmlBody, L"NEW BODY (udpated by Aspose.Email)");
    
    // Create an instance of type MapiMessage from MailMessage, Set message flag to un-sent (draft status) and Save it
    System::SharedPtr<MapiMessage> mapiMsg = MapiMessage::FromMailMessage(msg);
    mapiMsg->SetMessageFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT);
    mapiMsg->Save(dataDir + L"SavingMessageInDraftStatus_out.msg");
    // ExEnd:SavingMessageInDraftStatus
}







