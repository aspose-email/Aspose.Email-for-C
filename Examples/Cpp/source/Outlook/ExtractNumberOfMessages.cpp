/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void ExtractNumberOfMessages()
{
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + L"Sub.pst";
    
    // Save message to file
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        // ExStart:ExtractNnumberOfMessages
        System::SharedPtr<FolderInfo> inbox = personalStorage->get_RootFolder()->GetSubFolder(L"Inbox");
        
        // Extracts messages starting from 10th index top and extract total 100 messages
        System::SharedPtr<MessageInfoCollection> messages = inbox->GetContents(10, 100);
        // ExEnd:ExtractNnumberOfMessages   
    }
}







