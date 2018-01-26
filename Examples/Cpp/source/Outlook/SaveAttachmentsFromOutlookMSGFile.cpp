/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void SaveAttachmentsFromOutlookMSGFile()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = L"outputAttachments.msg";
    
    // ExStart:SaveAttachmentsFromOutlookMSGFile
    // Create an instance of MapiMessage from file
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(dataDir + fileName);
    
    // Iterate through the attachments collection
    
    {
        auto attachment_enumerator = (message->get_Attachments())->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {
            // Save the individual attachment
            attachment->Save(dataDir + attachment->get_FileName());
        }
    }
    // ExEnd:SaveAttachmentsFromOutlookMSGFile
}







