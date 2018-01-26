/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void DisplayInformationOfPSTFile()
{
    // ExStart:DisplayInformationOfPSTFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + L"PersonalStorage.pst";
    
    // load PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dst);
    
    // Get the folders information
    System::SharedPtr<FolderInfoCollection> folderInfoCollection = personalStorage->get_RootFolder()->GetSubFolders();
    
    // Browse through each folder to display folder name and number of messages
    
    {
        auto folderInfo_enumerator = (folderInfoCollection)->GetEnumerator();
        decltype(folderInfo_enumerator->get_Current()) folderInfo;
        while (folderInfo_enumerator->MoveNext() && (folderInfo = folderInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(L"Folder: ") + folderInfo->get_DisplayName());
            System::Console::WriteLine(System::String(L"Total items: ") + folderInfo->get_ContentCount());
            System::Console::WriteLine(System::String(L"Total unread items: ") + folderInfo->get_ContentUnreadCount());
            System::Console::WriteLine(L"-----------------------------------");
        }
    }
    // ExEnd:DisplayInformationOfPSTFile
}







