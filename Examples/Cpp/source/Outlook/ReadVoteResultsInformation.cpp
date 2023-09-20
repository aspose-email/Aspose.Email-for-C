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
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiRecipient.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadVoteResultsInformation()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:ReadVoteResultsInformation
    System::SharedPtr<MapiMessage> msg = MapiMessage::Load(dataDir + u"AddVotingButtonToExistingMessage.msg");
    
    {
        for (auto&& recipient : System::IterateOver(msg->get_Recipients()))
        {
            System::Console::WriteLine(System::String::Format(u"Recipient: {0}",recipient->get_DisplayName()));
            
            // Get the PR_RECIPIENT_AUTORESPONSE_PROP_RESPONSE property
            System::Console::WriteLine(System::String::Format(u"Response: {0}",recipient->get_Properties()->idx_get(MapiPropertyTag::PR_RECIPIENT_AUTORESPONSE_PROP_RESPONSE)->GetString()));
            
            // Get the PR_RECIPIENT_TRACKSTATUS_TIME property
            System::Console::WriteLine(System::String::Format(u"Response time: {0}",recipient->get_Properties()->idx_get(MapiPropertyTag::PR_RECIPIENT_TRACKSTATUS_TIME)->GetDateTime()));
            
            System::Console::WriteLine();
        }
    }
    // ExEnd:ReadVoteResultsInformation
}

