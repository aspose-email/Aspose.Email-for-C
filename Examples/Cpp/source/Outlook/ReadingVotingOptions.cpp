/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/FollowUpOptions.h>
#include <Mapi/FollowUpManager.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadingVotingOptions()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"MessageWithVotingButtons.msg";
    
    // ExStart:ReadingVotingOptions
    System::SharedPtr<MapiMessage> message = MapiMessage::Load(fileName);
    
    // This method can be useful when except voting buttons it is necessary to get other parameters (ex. a category)
    System::SharedPtr<FollowUpOptions> options = FollowUpManager::GetOptions(message);
    
    // Voting buttons will be introduced as a string with semi-column as a separator
    System::String votingButtons = options->get_VotingButtons();
    // ExEnd:ReadingVotingOptions
}

