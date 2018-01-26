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
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void LoadMSGFiles()
{
    // ExStart:LoadMSGFiles
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create an instance of MapiMessage from file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"message.msg");
    
    // Get subject
    System::Console::WriteLine(System::String(L"Subject:") + msg->get_Subject());
    
    // Get from address
    System::Console::WriteLine(System::String(L"From:") + msg->get_SenderEmailAddress());
    
    // Get body
    System::Console::WriteLine(System::String(L"Body") + msg->get_Body());
    
    // Get recipients information
    System::Console::WriteLine(System::String(L"Recipient: ") + msg->get_Recipients());
    
    // Get attachments
    
    {
        auto att_enumerator = (msg->get_Attachments())->GetEnumerator();
        decltype(att_enumerator->get_Current()) att;
        while (att_enumerator->MoveNext() && (att = att_enumerator->get_Current(), true))
        {
            System::Console::Write(System::String(L"Attachment Name: ") + att->get_FileName());
            System::Console::Write(System::String(L"Attachment Display Name: ") + att->get_DisplayName());
        }
    }
    // ExEnd:LoadMSGFiles
}







