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
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiObjectProperty.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <Mapi/MailConversionOptions.h>
#include <MailMessage.h>
#include <EmlSaveOptions.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void GetNestedMailMessageAttachments()
{
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(dataDir + u"messageWithEmbeddedEML.msg");
    System::SharedPtr<MapiAttachment> attachment = message->get_Attachments()->idx_get(0);
    
    // ExStart:GetNestedMailMessageAttachments
    // Create a MapiMessage object from the individual attachment
    System::SharedPtr<MapiMessage> getAttachment = MapiMessage::FromProperties(attachment->get_ObjectData()->get_Properties());
    
    // Create object of type MailMessageImterpretor from the above message and Save the embedded message to file at disk
    System::SharedPtr<MailMessage> mailMessage = getAttachment->ToMailMessage(System::MakeObject<MailConversionOptions>());
    mailMessage->Save(dataDir + u"NestedMailMessageAttachments_out.eml", SaveOptions::get_DefaultEml());
    // ExEnd:GetNestedMailMessageAttachments
}

