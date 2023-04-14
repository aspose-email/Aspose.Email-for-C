/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiContactNamePropertySet.h>
#include <Mapi/MapiContact.h>
#include <Mapi/IMapiMessageItem.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void AccessContactInformation()
{
    // ExStart:AccessContactInformation
    // Load the Outlook file
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"SampleContacts.pst");
    // Get the Contacts folder
    System::SharedPtr<FolderInfo> folderInfo = personalStorage->get_RootFolder()->GetSubFolder(u"Contacts");
    // Loop through all the contacts in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();
    
    {
        for (auto&& messageInfo : messageInfoCollection)
        {
            // Get the contact information
            System::SharedPtr<MapiMessage> mapi = personalStorage->ExtractMessage(messageInfo);
            
            System::SharedPtr<MapiContact> contact = System::ExplicitCast<Aspose::Email::Mapi::MapiContact>(mapi->ToMapiMessageItem());
            
            // Display some contents on screen
            System::Console::WriteLine(System::String(u"Name: ") + contact->get_NameInfo()->get_DisplayName());
            // Save to disk in MSG format
            if (contact->get_NameInfo()->get_DisplayName() != nullptr)
            {
                System::SharedPtr<MapiMessage> message = personalStorage->ExtractMessage(messageInfo);
                // Get rid of illegal characters that cannot be used as a file name
                System::String messageName = message->get_Subject().Replace(u":", u" ").Replace(u"\\", u" ").Replace(u"?", u" ").Replace(u"/", u" ");
                message->Save(dataDir + u"Contacts\\" + messageName + u"_out.msg");
            }
        }
    }
    // ExEnd:AccessContactInformation
}

