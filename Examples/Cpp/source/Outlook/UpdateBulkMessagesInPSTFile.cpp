/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <system/collections/ilist.h>
#include <system/collections/ienumerator.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;
using namespace Aspose::Email::Mapi;

void UpdateBulkMessagesInPSTFile()
{
    // ExStart:UpdateBulkMessagesInPSTFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook() + u"Sub.pst";
    
    // Load the Outlook PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
    
    // Get Requierd Subfolder 
    System::SharedPtr<FolderInfo> inbox = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
    
    // find messages having From = "someuser@domain.com"
    System::SharedPtr<PersonalStorageQueryBuilder> queryBuilder = System::MakeObject<PersonalStorageQueryBuilder>();
    queryBuilder->get_From()->Contains(u"someuser@domain.com");
    
    // Get Contents from Query
    System::SharedPtr<MessageInfoCollection> messages = inbox->GetContents(queryBuilder->GetQuery());
    
    // Save (MessageInfo,EntryIdString) in List
    System::SharedPtr<System::Collections::Generic::IList<System::String>> changeList = System::MakeObject<System::Collections::Generic::List<System::String>>();
    
    {
        for (auto&& messageInfo : messages)
        {
            changeList->Add(messageInfo->get_EntryIdString());
        }
    }
    
    // Compose the new properties
    System::SharedPtr<MapiPropertyCollection> updatedProperties = System::MakeObject<MapiPropertyCollection>();
    updatedProperties->Add(MapiPropertyTag::PR_SUBJECT_W, System::MakeObject<MapiProperty>(MapiPropertyTag::PR_SUBJECT_W, System::Text::Encoding::get_Unicode()->GetBytes(u"New Subject")));
    updatedProperties->Add(MapiPropertyTag::PR_IMPORTANCE, System::MakeObject<MapiProperty>(MapiPropertyTag::PR_IMPORTANCE, System::BitConverter::GetBytes((int64_t)2)));
    
    // update messages having From = "someuser@domain.com" with new properties
    inbox->ChangeMessages(changeList, updatedProperties);
    // ExEnd:UpdateBulkMessagesInPSTFile
}

