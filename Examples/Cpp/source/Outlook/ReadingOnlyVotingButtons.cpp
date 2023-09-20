//using System.Collections;
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
#include <system/io/memory_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/FollowUpManager.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Mapi;


void ReadingOnlyVotingButtons()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"MessageWithVotingButtons.msg";
    
    {
        System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>(System::IO::File::ReadAllBytes(fileName));
        
        // ------------------------------------------
        // ExStart:ReadingOnlyVotingButtons
        System::SharedPtr<MapiMessage> testMsg = MapiMessage::Load(ms);
        
        // This method can be useful when it is necessary to read only voting buttons Voting buttons will be introduced as a collection of string values
        System::ArrayPtr<System::String> buttons = FollowUpManager::GetVotingButtons(testMsg);
        // ExEnd:ReadingOnlyVotingButtons
    }
    
}







