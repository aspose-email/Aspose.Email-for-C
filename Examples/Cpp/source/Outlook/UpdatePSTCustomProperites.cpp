/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerable.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiPropertyType.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiNamedProperty.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

int64_t GenerateNamedPropertyTag(int64_t index, Aspose::Email::Mapi::MapiPropertyType dataType)
{
    return ((int64_t)(int64_t)dataType | (0x8000 | index) << 16) & 0x00000000FFFFFFFF;
}


void UpdatePSTCustomProperites()
{
    // Load the Outlook file
    System::String dataDir = GetDataDir_Outlook() + u"Outlook.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> testFolder = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
            
            // Create the collection of message properties for adding or updating
            System::SharedPtr<MapiPropertyCollection> newProperties = System::MakeObject<MapiPropertyCollection>();
            
            // Normal,  Custom and PidLidLogFlags named  property
            System::SharedPtr<MapiProperty> property = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_ORG_EMAIL_ADDR_W, System::Text::Encoding::get_Unicode()->GetBytes(u"test_address@org.com"));
            System::SharedPtr<MapiProperty> namedProperty1 = System::MakeObject<MapiNamedProperty>(GenerateNamedPropertyTag(0, Aspose::Email::Mapi::MapiPropertyType::PT_LONG), u"ITEM_ID", System::Guid::NewGuid(), System::BitConverter::GetBytes(123));
            System::SharedPtr<MapiProperty> namedProperty2 = System::MakeObject<MapiNamedProperty>(GenerateNamedPropertyTag(1, Aspose::Email::Mapi::MapiPropertyType::PT_LONG), 0x0000870C, System::Guid(u"0006200A-0000-0000-C000-000000000046"), System::BitConverter::GetBytes(0));
            newProperties->Add(namedProperty1->get_Tag(), namedProperty1);
            newProperties->Add(namedProperty2->get_Tag(), namedProperty2);
            newProperties->Add(property->get_Tag(), property);
            testFolder->ChangeMessages(testFolder->EnumerateMessagesEntryId(), newProperties);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
}


