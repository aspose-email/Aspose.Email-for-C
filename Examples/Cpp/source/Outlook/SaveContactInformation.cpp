/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
 * 
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
#include <Formats/Outlook/Mapi/MapiContactNamePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContact.h>
#include <Formats/Outlook/Mapi/ContactSaveFormat.h>
#include <Formats/Outlook/IMapiMessageItem.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void SaveContactInformation()
{
    // ExStart:SaveContactInformation
    // Load the Outlook file
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + L"Outlook.pst");
    // Get the Contacts folder
    System::SharedPtr<FolderInfo> folderInfo = personalStorage->get_RootFolder()->GetSubFolder(L"Contacts");
    // Loop through all the contacts in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();
    
    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            // Get the contact information
            System::SharedPtr<MapiContact> contact = System::DynamicCast<Aspose::Email::Outlook::MapiContact>(personalStorage->ExtractMessage(messageInfo)->ToMapiMessageItem());
            // Display some contents on screen
            System::Console::WriteLine(System::String(L"Name: ") + contact->get_NameInfo()->get_DisplayName() + L" - " + messageInfo->get_EntryIdString());
            // Save to disk in vCard VCF format
            contact->Save(dataDir + L"Contacts\\" + contact->get_NameInfo()->get_DisplayName() + L".vcf", Aspose::Email::Outlook::ContactSaveFormat::VCard);
        }
    }
    // ExEnd:SaveContactInformation
}







