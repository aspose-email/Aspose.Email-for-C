/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/MapiDistributionListMemberCollection.h>
#include <Formats/Outlook/Mapi/MapiDistributionListMember.h>
#include <Formats/Outlook/Mapi/MapiDistributionListEntryIdType.h>
#include <Formats/Outlook/Mapi/MapiDistributionList.h>
#include <Formats/Outlook/Mapi/MapiContact.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void CreateDistributionListInPST()
{
    // The path to the File directory.
    // ExStart:CreateDistributionListInPST
    System::String dataDir = GetDataDir_Outlook();
    
    System::String displayName1 = L"Sebastian Wright";
    System::String email1 = L"SebastianWright@dayrep.com";
    
    System::String displayName2 = L"Wichert Kroos";
    System::String email2 = L"WichertKroos@teleworm.us";
    
    System::String strEntryId1;
    System::String strEntryId2;
    
    System::String path = dataDir + L"CreateDistributionListInPST_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    // Create distribution list from contacts
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"CreateDistributionListInPST_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        // Add the contact folder to pst
        System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(L"Contacts", Aspose::Email::Outlook::Pst::StandardIpmFolder::Contacts);
        
        // Create contacts
        strEntryId1 = contactFolder->AddMapiMessageItem(System::MakeObject<MapiContact>(displayName1, email1));
        strEntryId2 = contactFolder->AddMapiMessageItem(System::MakeObject<MapiContact>(displayName2, email2));
        
        // Create distribution list on the base of the created contacts
        System::SharedPtr<MapiDistributionListMember> member1 = System::MakeObject<MapiDistributionListMember>(displayName1, email1);
        member1->set_EntryIdType(Aspose::Email::Outlook::MapiDistributionListEntryIdType::Contact);
        member1->set_EntryId(System::Convert::FromBase64String(strEntryId1));
        
        System::SharedPtr<MapiDistributionListMember> member2 = System::MakeObject<MapiDistributionListMember>(displayName2, email2);
        member2->set_EntryIdType(Aspose::Email::Outlook::MapiDistributionListEntryIdType::Contact);
        member2->set_EntryId(System::Convert::FromBase64String(strEntryId2));
        
        System::SharedPtr<MapiDistributionListMemberCollection> members = System::MakeObject<MapiDistributionListMemberCollection>();
        members->Add(member1);
        members->Add(member2);
        
        System::SharedPtr<MapiDistributionList> distributionList = System::MakeObject<MapiDistributionList>(L"Contact list", members);
        distributionList->set_Body(L"Distribution List Body");
        distributionList->set_Subject(L"Sample Distribution List using Aspose.Email");
        
        // Add distribution list to PST
        contactFolder->AddMapiMessageItem(distributionList);
    }
    
    
    System::String path1 = dataDir + L"CreateDistributionListInPST_OneOffmembers_out.pst";
    
    if (System::IO::File::Exists(path1))
    {
        System::IO::File::Delete(path1);
    }
    
    // Create one-off distribution list members (for which no separate contacts were created)
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"CreateDistributionListInPST_OneOffmembers_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_1{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        // Add the contact folder to pst
        System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(L"Contacts", Aspose::Email::Outlook::Pst::StandardIpmFolder::Contacts);
        
        System::SharedPtr<MapiDistributionListMemberCollection> oneOffmembers = System::MakeObject<MapiDistributionListMemberCollection>();
        oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(L"John R. Patrick", L"JohnRPatrick@armyspy.com"));
        oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(L"Tilly Bates", L"TillyBates@armyspy.com"));
        
        System::SharedPtr<MapiDistributionList> oneOffMembersList = System::MakeObject<MapiDistributionList>(L"Simple list", oneOffmembers);
        contactFolder->AddMapiMessageItem(oneOffMembersList);
    }
    // ExEnd:CreateDistributionListInPST
}







