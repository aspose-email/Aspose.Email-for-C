/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
#include <system/array.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiDistributionListMemberCollection.h>
#include <Mapi/MapiDistributionListMember.h>
#include <Mapi/MapiDistributionListEntryIdType.h>
#include <Mapi/MapiDistributionList.h>
#include <Mapi/MapiContact.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void CreateDistributionListInPST()
{
    // The path to the File directory.
    // ExStart:CreateDistributionListInPST
    System::String dataDir = GetDataDir_Outlook();
    
    System::String displayName1 = u"Sebastian Wright";
    System::String email1 = u"SebastianWright@dayrep.com";
    
    System::String displayName2 = u"Wichert Kroos";
    System::String email2 = u"WichertKroos@teleworm.us";
    
    System::String strEntryId1;
    System::String strEntryId2;
    
    System::String path = dataDir + u"CreateDistributionListInPST_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    // Create distribution list from contacts
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"CreateDistributionListInPST_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            // Add the contact folder to pst
            System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(u"Contacts", Aspose::Email::Storage::Pst::StandardIpmFolder::Contacts);
            
            // Create contacts
            strEntryId1 = contactFolder->AddMapiMessageItem(System::MakeObject<MapiContact>(displayName1, email1));
            strEntryId2 = contactFolder->AddMapiMessageItem(System::MakeObject<MapiContact>(displayName2, email2));
            
            // Create distribution list on the base of the created contacts
            System::SharedPtr<MapiDistributionListMember> member1 = System::MakeObject<MapiDistributionListMember>(displayName1, email1);
            member1->set_EntryIdType(Aspose::Email::Mapi::MapiDistributionListEntryIdType::Contact);
            member1->set_EntryId(System::Convert::FromBase64String(strEntryId1));
            
            System::SharedPtr<MapiDistributionListMember> member2 = System::MakeObject<MapiDistributionListMember>(displayName2, email2);
            member2->set_EntryIdType(Aspose::Email::Mapi::MapiDistributionListEntryIdType::Contact);
            member2->set_EntryId(System::Convert::FromBase64String(strEntryId2));
            
            System::SharedPtr<MapiDistributionListMemberCollection> members = System::MakeObject<MapiDistributionListMemberCollection>();
            members->Add(member1);
            members->Add(member2);
            
            System::SharedPtr<MapiDistributionList> distributionList = System::MakeObject<MapiDistributionList>(u"Contact list", members);
            distributionList->set_Body(u"Distribution List Body");
            distributionList->set_Subject(u"Sample Distribution List using Aspose.Email");
            
            // Add distribution list to PST
            contactFolder->AddMapiMessageItem(distributionList);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    
    
    System::String path1 = dataDir + u"CreateDistributionListInPST_OneOffmembers_out.pst";
    
    if (System::IO::File::Exists(path1))
    {
        System::IO::File::Delete(path1);
    }
    
    // Create one-off distribution list members (for which no separate contacts were created)
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"CreateDistributionListInPST_OneOffmembers_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ personalStorage});
        // ------------------------------------------
        
        try
        {
            // Add the contact folder to pst
            System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(u"Contacts", Aspose::Email::Storage::Pst::StandardIpmFolder::Contacts);
            
            System::SharedPtr<MapiDistributionListMemberCollection> oneOffmembers = System::MakeObject<MapiDistributionListMemberCollection>();
            oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(u"John R. Patrick", u"JohnRPatrick@armyspy.com"));
            oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(u"Tilly Bates", u"TillyBates@armyspy.com"));
            
            System::SharedPtr<MapiDistributionList> oneOffMembersList = System::MakeObject<MapiDistributionList>(u"Simple list", oneOffmembers);
            contactFolder->AddMapiMessageItem(oneOffMembersList);
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:CreateDistributionListInPST
}

