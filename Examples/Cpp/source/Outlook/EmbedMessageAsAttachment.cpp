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
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void EmbedMessageAsAttachment()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:EmbedMessageAsAttachment
    System::SharedPtr<MapiMessage> message = System::MakeObject<MapiMessage>(L"from@test.com", L"to@test.com", L"Subj", L"This is a message body");
    System::SharedPtr<MapiMessage> attachMsg = MapiMessage::FromFile(dataDir + L"Message.msg");
    message->get_Attachments()->Add(L"Weekly report.msg", attachMsg);
    message->Save(dataDir + L"WithEmbeddedMsg_out.msg");
    // ExEnd:EmbedMessageAsAttachment
}







