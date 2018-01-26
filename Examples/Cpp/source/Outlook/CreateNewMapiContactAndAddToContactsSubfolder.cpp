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
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/MapiContactTelephonePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactProfessionalPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddress.h>
#include <Formats/Outlook/Mapi/MapiContactPersonalInfoPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactNamePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactGender.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddress.h>
#include <Formats/Outlook/Mapi/MapiContact.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void CreateNewMapiContactAndAddToContactsSubfolder()
{
    // The path to the File directory.
    // ExStart:CreateNewMapiContactAndAddToContactsSubfolder
    System::String dataDir = GetDataDir_Outlook();
    
    // Create three Contacts 
    System::SharedPtr<MapiContact> contact1 = System::MakeObject<MapiContact>(L"Sebastian Wright", L"SebastianWright@dayrep.com");
    System::SharedPtr<MapiContact> contact2 = System::MakeObject<MapiContact>(L"Wichert Kroos", L"WichertKroos@teleworm.us", L"Grade A Investment");
    System::SharedPtr<MapiContact> contact3 = System::MakeObject<MapiContact>(L"Christoffer van de Meeberg", L"ChristoffervandeMeeberg@teleworm.us", L"Krauses Sofa Factory", L"046-630-4614046-630-4614");
    
    // Contact #4
    System::SharedPtr<MapiContact> contact4 = System::MakeObject<MapiContact>();
    contact4->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(L"Margaret", L"J.", L"Tolle"));
    contact4->get_PersonalInfo()->set_Gender(Aspose::Email::Outlook::MapiContactGender::Female);
    contact4->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(L"Adaptaz", L"Recording engineer"));
    contact4->get_PhysicalAddresses()->get_WorkAddress()->set_Address(L"4 Darwinia Loop EIGHTY MILE BEACH WA 6725");
    contact4->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(L"Hisen1988", L"SMTP", L"MargaretJTolle@dayrep.com"));
    contact4->get_Telephones()->set_BusinessTelephoneNumber(L"(08)9080-1183");
    contact4->get_Telephones()->set_MobileTelephoneNumber(L"(925)599-3355(925)599-3355");
    
    // Contact #5
    System::SharedPtr<MapiContact> contact5 = System::MakeObject<MapiContact>();
    contact5->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(L"Matthew", L"R.", L"Wilcox"));
    contact5->get_PersonalInfo()->set_Gender(Aspose::Email::Outlook::MapiContactGender::Male);
    contact5->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(L"Briazz", L"Psychiatric aide"));
    contact5->get_PhysicalAddresses()->get_WorkAddress()->set_Address(L"Horner Strasse 12 4421 SAASS");
    contact5->get_Telephones()->set_BusinessTelephoneNumber(L"0650 675 73 300650 675 73 30");
    contact5->get_Telephones()->set_HomeTelephoneNumber(L"(661)387-5382(661)387-5382");
    
    // Contact #6
    System::SharedPtr<MapiContact> contact6 = System::MakeObject<MapiContact>();
    contact6->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(L"Bertha", L"A.", L"Buell"));
    contact6->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(L"Awthentikz", L"Social work assistant"));
    contact6->get_PersonalInfo()->set_PersonalHomePage(L"B2BTies.com");
    contact6->get_PhysicalAddresses()->get_WorkAddress()->set_Address(L"Im Astenfeld 59 8580 EDELSCHROTT");
    contact6->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(L"Experwas", L"SMTP", L"BerthaABuell@armyspy.com"));
    contact6->set_Telephones(System::MakeObject<MapiContactTelephonePropertySet>(L"06605045265"));
    
    // Load the Outlook file
    System::String path = dataDir + L"SampleContacts_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"SampleContacts_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(L"Contacts", Aspose::Email::Outlook::Pst::StandardIpmFolder::Contacts);
        contactFolder->AddMapiMessageItem(contact1);
        contactFolder->AddMapiMessageItem(contact2);
        contactFolder->AddMapiMessageItem(contact3);
        contactFolder->AddMapiMessageItem(contact4);
        contactFolder->AddMapiMessageItem(contact5);
        contactFolder->AddMapiMessageItem(contact6);
    }
    // ExEnd:CreateNewMapiContactAndAddToContactsSubfolder
}







