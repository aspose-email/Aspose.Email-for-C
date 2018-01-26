/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/IMapiMessageItem.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void SaveCalendarItems()
{
    // ExStart:SaveCalendarItems
    // The path to the documents directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(dataDir + L"Sub.pst");
    // Get the Calendar folder
    System::SharedPtr<FolderInfo> folderInfo = pst->get_RootFolder()->GetSubFolder(L"Inbox");
    // Loop through all the calendar items in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();
    
    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            // Get the calendar information
            System::SharedPtr<MapiMessage> calendar = System::DynamicCast<Aspose::Email::Outlook::MapiMessage>(pst->ExtractMessage(messageInfo)->ToMapiMessageItem());
            // Display some contents on screen
            System::Console::WriteLine(System::String(L"Name: ") + calendar->get_Subject());
            // Save to disk in ICS format
            calendar->Save(dataDir + L"\\Calendar\\" + calendar->get_Subject() + L"_out.ics");
        }
    }
    // ExEnd:SaveCalendarItems
}







