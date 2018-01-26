/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Mapi/MapiRecipientTrackStatus.h>
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiRecipient.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void DisplayRecipientsStatusFromMeetingRequest()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + L"Test Meeting.msg";
    
    // ExStart:DisplayRecipientsStatusFromMeetingRequest
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(fileName);
    
    {
        auto recipient_enumerator = (message->get_Recipients())->GetEnumerator();
        decltype(recipient_enumerator->get_Current()) recipient;
        while (recipient_enumerator->MoveNext() && (recipient = recipient_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::ObjectExt::ToString(recipient->get_RecipientTrackStatus()));
        }
    }
    // ExEnd:DisplayRecipientsStatusFromMeetingRequest
}







