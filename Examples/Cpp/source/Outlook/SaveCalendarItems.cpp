/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/IMapiMessageItem.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void SaveCalendarItems()
{
    // ExStart:SaveCalendarItems
    // The path to the documents directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(dataDir + u"Sub.pst");
    // Get the Calendar folder
    System::SharedPtr<FolderInfo> folderInfo = pst->get_RootFolder()->GetSubFolder(u"Inbox");
    // Loop through all the calendar items in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();
    
    {
        for (auto&& messageInfo : messageInfoCollection)
        {
            // Get the calendar information
            System::SharedPtr<MapiMessage> calendar = System::DynamicCast<Aspose::Email::Mapi::MapiMessage>(pst->ExtractMessage(messageInfo)->ToMapiMessageItem());
            // Display some contents on screen
            System::Console::WriteLine(System::String(u"Name: ") + calendar->get_Subject());
            // Save to disk in ICS format
            calendar->Save(dataDir + u"\\Calendar\\" + calendar->get_Subject() + u"_out.ics");
        }
    }
    // ExEnd:SaveCalendarItems
}

