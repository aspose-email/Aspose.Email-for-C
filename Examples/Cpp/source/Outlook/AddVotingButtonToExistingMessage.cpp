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
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void AddVotingButtonToExistingMessage()
{
    // ExStart:AddVotingButtonToExistingMessage
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromFile(dataDir + L"message.msg");
    FollowUpManager::AddVotingButton(mapi, L"Indeed!");
    mapi->Save(dataDir + L"AddVotingButtonToExistingMessage_out.msg");
    // ExEnd:AddVotingButtonToExistingMessage
}







