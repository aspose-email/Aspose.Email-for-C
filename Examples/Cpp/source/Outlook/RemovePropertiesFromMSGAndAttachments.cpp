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
#include <system/console.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <Formats/Outlook/Mapi/BodyContentType.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;


void RemovePropertiesFromMSGAndAttachments()
{
    // ExStart:RemovePropertiesFromMSGAndAttachments
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> mapi = System::MakeObject<MapiMessage>(L"from@doamin.com", L"to@domain.com", L"subject", L"body");
    mapi->SetBodyContent(L"<html><body><h1>This is the body content</h1></body></html>", Aspose::Email::Outlook::BodyContentType::Html);
    System::SharedPtr<MapiMessage> attachment = MapiMessage::FromFile(dataDir + L"message.msg");
    mapi->get_Attachments()->Add(L"Outlook2 Test subject.msg", attachment);
    System::Console::WriteLine(System::String(L"Before removal = ") + mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    
    mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->RemoveProperty(923467779);
    // Delete anyone property
    System::Console::WriteLine(System::String(L"After removal = ") + mapi->get_Attachments()->idx_get(mapi->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    mapi->Save(L"EMAIL_589265.msg");
    
    System::SharedPtr<MapiMessage> mapi2 = MapiMessage::FromFile(L"EMAIL_589265.msg");
    System::Console::WriteLine(System::String(L"Reloaded = ") + mapi2->get_Attachments()->idx_get(mapi2->get_Attachments()->get_Count() - 1)->get_Properties()->get_Count());
    // ExEnd:RemovePropertiesFromMSGAndAttachments
}







