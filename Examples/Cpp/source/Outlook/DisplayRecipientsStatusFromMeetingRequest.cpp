/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mapi/MapiRecipientTrackStatus.h>
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiRecipient.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void DisplayRecipientsStatusFromMeetingRequest()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"Test Meeting.msg";
    
    // ExStart:DisplayRecipientsStatusFromMeetingRequest
    System::SharedPtr<MapiMessage> message = MapiMessage::Load(fileName);
    
    {
        for (auto&& recipient : System::IterateOver(message->get_Recipients()))
        {
            System::Console::WriteLine(System::ObjectExt::Box<MapiRecipientTrackStatus>(recipient->get_RecipientTrackStatus()));
        }
    }
    // ExEnd:DisplayRecipientsStatusFromMeetingRequest
}

