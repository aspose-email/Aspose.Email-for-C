/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void AddMessagesToPSTFiles()
{
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook() + L"AddMessagesToPSTFiles_out.pst";
    
    if (System::IO::File::Exists(dataDir))
    {
        System::IO::File::Delete(dataDir);
    }
    else { }
    
    // ExStart:AddMessagesToPSTFiles
    // Create new PST            
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir, Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
    
    // Add new folder "Inbox"
    personalStorage->get_RootFolder()->AddSubFolder(L"Inbox");
    
    // Select the "Inbox" folder
    System::SharedPtr<FolderInfo> inboxFolder = personalStorage->get_RootFolder()->GetSubFolder(L"Inbox");
    
    // Add some messages to "Inbox" folder
    inboxFolder->AddMessage(MapiMessage::FromFile(GetDataDir_Outlook() + L"MapiMsgWithPoll.msg"));
    // ExEnd:AddMessagesToPSTFiles            
}







