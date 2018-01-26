/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;
using namespace Aspose::Email;


void DeleteMessagesFromPSTFiles()
{
    // ExStart:DeleteMessagesFromPSTFiles
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook() + L"Sub.pst";
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
    
    // Get the Sent items folder
    System::SharedPtr<FolderInfo> folderInfo = personalStorage->GetPredefinedFolder(Aspose::Email::Outlook::Pst::StandardIpmFolder::SentItems);
    
    System::SharedPtr<MessageInfoCollection> msgInfoColl = folderInfo->GetContents();
    
    {
        auto msgInfo_enumerator = (msgInfoColl)->GetEnumerator();
        decltype(msgInfo_enumerator->get_Current()) msgInfo;
        while (msgInfo_enumerator->MoveNext() && (msgInfo = msgInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(msgInfo->get_Subject() + L": " + msgInfo->get_EntryIdString());
            if (System::ObjectExt::Equals(msgInfo->get_Subject(), L"some delete condition") == true)
            {
                // Delete this item
                folderInfo->DeleteChildItem(msgInfo->get_EntryId());
                System::Console::WriteLine(L"Deleted this message");
            }
        }
    }
    // ExEnd:DeleteMessagesFromPSTFiles
}







