/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <Mapi/MapiMessageFlags.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/FollowUpOptions.h>
#include <Mapi/FollowUpManager.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

static System::SharedPtr<Aspose::Email::Mapi::MapiMessage> CreateTestMessage(bool draft)
{
    // ExEnd:CreateTestMessage
    System::SharedPtr<MapiMessage> msg = System::MakeObject<MapiMessage>(u"from@test.com", u"to@test.com", u"Flagged message", u"Make it nice and short, but descriptive. The description may appear in search engines' search results pages...");

    if (!draft)
    {
        msg->SetMessageFlags(msg->get_Flags() ^ Aspose::Email::Mapi::MapiMessageFlags::MSGFLAG_UNSENT);
    }
    return msg;
    // ExEnd:CreateTestMessage
}


void DeleteVotingButtonFromMessage()
{
    // ExStart:DeletVotingButtonFromMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create New Message and set FollowUpOptions, FollowUpManager properties
    System::SharedPtr<MapiMessage> msg = CreateTestMessage(false);
    
    System::SharedPtr<FollowUpOptions> options = System::MakeObject<FollowUpOptions>();
    options->set_VotingButtons(u"Yes;No;Maybe;Exactly!");
    FollowUpManager::SetOptions(msg, options);
    msg->Save(dataDir + u"MapiMsgWithPoll.msg");
    FollowUpManager::RemoveVotingButton(msg, u"Exactly!");
    // Deleting a single button OR
    FollowUpManager::ClearVotingButtons(msg);
    // Deleting all buttons from a MapiMessage
    msg->Save(dataDir + u"MapiMsgWithPoll.msg");
    // ExEnd:DeletVotingButtonFromMessage
}


