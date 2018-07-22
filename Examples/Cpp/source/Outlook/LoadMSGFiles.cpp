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
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void LoadMSGFiles()
{
    // ExStart:LoadMSGFiles
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create an instance of MapiMessage from file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + u"message.msg");
    
    // Get subject
    System::Console::WriteLine(System::String(u"Subject:") + msg->get_Subject());
    
    // Get from address
    System::Console::WriteLine(System::String(u"From:") + msg->get_SenderEmailAddress());
    
    // Get body
    System::Console::WriteLine(System::String(u"Body") + msg->get_Body());
    
    // Get recipients information
    System::Console::WriteLine(System::String(u"Recipient: ") + msg->get_Recipients());
    
    // Get attachments
    
    {
        auto att_enumerator = (msg->get_Attachments())->GetEnumerator();
        decltype(att_enumerator->get_Current()) att;
        while (att_enumerator->MoveNext() && (att = att_enumerator->get_Current(), true))
        {
            System::Console::Write(System::String(u"Attachment Name: ") + att->get_FileName());
            System::Console::Write(System::String(u"Attachment Display Name: ") + att->get_DisplayName());
        }
    }
    // ExEnd:LoadMSGFiles
}

