/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/FollowUpOptions.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void ReadingVotingOptions()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + L"MessageWithVotingButtons.msg";
    
    // ExStart:ReadingVotingOptions
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(fileName);
    
    // This method can be useful when except voting buttons it is necessary to get other parameters (ex. a category)
    System::SharedPtr<FollowUpOptions> options = FollowUpManager::GetOptions(message);
    
    // Voting buttons will be introduced as a string with semi-column as a separator
    System::String votingButtons = options->get_VotingButtons();
    // ExEnd:ReadingVotingOptions
}







