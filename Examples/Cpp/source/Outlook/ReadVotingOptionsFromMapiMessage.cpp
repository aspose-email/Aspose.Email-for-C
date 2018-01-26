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
#include <system/enum_helpers.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/FollowUpOptions.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


System::SharedPtr<Aspose::Email::Outlook::MapiMessage> CreateTestMessage(bool draft)
{
    // ExStart:CreateTestMessage
    System::SharedPtr<MapiMessage> msg = System::MakeObject<MapiMessage>(L"from@test.com", L"to@test.com", L"Flagged message", L"Make it nice and short, but descriptive. The description may appear in search engines' search results pages...");

    if (!draft)
    {
        msg->SetMessageFlags(msg->get_Flags() ^ Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT);
    }
    return msg;
    // ExEnd:CreateTestMessage
}

void ReadVotingOptionsFromMapiMessage()
{
    // ExStart:ReadVotingOptionsFromMapiMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create new Message
    System::SharedPtr<MapiMessage> msg = CreateTestMessage(false);
    
    // Set FollowUpOptions Properties
    System::SharedPtr<FollowUpOptions> options = System::MakeObject<FollowUpOptions>();
    options->set_VotingButtons(L"Yes;No;Maybe;Exactly!");
    
    FollowUpManager::SetOptions(msg, options);
    msg->Save(dataDir + L"MapiMsgWithPoll.msg");
    // ExEnd:ReadVotingOptionsFromMapiMessage
    
}








