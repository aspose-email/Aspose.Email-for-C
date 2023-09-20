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
#include <system/console.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <Mapi/BodyContentType.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void RemovePropertiesFromMSGAndAttachments()
{
    // ExStart:RemovePropertiesFromMSGAndAttachments
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> mapi = System::MakeObject<MapiMessage>(u"from@doamin.com", u"to@domain.com", u"subject", u"body");
    mapi->SetBodyContent(u"<html><body><h1>This is the body content</h1></body></html>", Aspose::Email::Mapi::BodyContentType::Html);
    System::SharedPtr<MapiMessage> attachment = MapiMessage::Load(dataDir + u"message.msg");
    mapi->get_Attachments()->Add(u"Outlook2 Test subject.msg", attachment);
    System::Console::WriteLine(System::String(u"Before removal = ") + mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    
    mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->RemoveProperty(923467779);
    // Delete anyone property
    System::Console::WriteLine(System::String(u"After removal = ") + mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    mapi->Save(u"EMAIL_589265.msg");
    
    System::SharedPtr<MapiMessage> mapi2 = MapiMessage::Load(u"EMAIL_589265.msg");
    System::Console::WriteLine(System::String(u"Reloaded = ") + mapi2->get_Attachments()->idx_get(mapi2->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    // ExEnd:RemovePropertiesFromMSGAndAttachments
}

