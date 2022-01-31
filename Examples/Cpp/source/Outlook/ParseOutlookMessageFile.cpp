/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ParseOutlookMessageFile()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // Load Microsoft Outlook email message file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(dataDir + u"Message.eml");
    
    // Obtain subject of the email message, SenderName, body and attachments count
    System::Console::WriteLine(System::String(u"Subject:") + msg->get_Subject());
    System::Console::WriteLine(System::String(u"From:") + msg->get_SenderName());
    System::Console::WriteLine(System::String(u"Body:") + msg->get_Body());
    System::Console::WriteLine(System::String(u"Attachment Count:") + msg->get_Attachments()->get_Count());
    
    // Iterate through the attachments
    
    {
        for (auto&& attachment : msg->get_Attachments())
        {
            System::Console::WriteLine(System::String(u"Attachment:") + attachment->get_FileName());
            attachment->Save(attachment->get_LongFileName());
        }
    }
}

