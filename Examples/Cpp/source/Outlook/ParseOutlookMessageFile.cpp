/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void ParseOutlookMessageFile()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // Load Microsoft Outlook email message file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(dataDir + L"Message.eml");
    
    // Obtain subject of the email message, SenderName, body and attachments count
    System::Console::WriteLine(System::String(L"Subject:") + msg->get_Subject());
    System::Console::WriteLine(System::String(L"From:") + msg->get_SenderName());
    System::Console::WriteLine(System::String(L"Body:") + msg->get_Body());
    System::Console::WriteLine(System::String(L"Attachment Count:") + msg->get_Attachments()->get_Count());
    
    // Iterate through the attachments
    
    {
        auto attachment_enumerator = (msg->get_Attachments())->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(L"Attachment:") + attachment->get_FileName());
            attachment->Save(attachment->get_LongFileName());
        }
    }
}







