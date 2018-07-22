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
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiContactTelephonePropertySet.h>
#include <Mapi/MapiContactProfessionalPropertySet.h>
#include <Mapi/MapiContactPhysicalAddressPropertySet.h>
#include <Mapi/MapiContactPhysicalAddress.h>
#include <Mapi/MapiContactPersonalInfoPropertySet.h>
#include <Mapi/MapiContactNamePropertySet.h>
#include <Mapi/MapiContactGender.h>
#include <Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Mapi/MapiContactElectronicAddress.h>
#include <Mapi/MapiContact.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void CreateNewMapiContactAndAddToContactsSubfolder()
{
    // The path to the File directory.
    // ExStart:CreateNewMapiContactAndAddToContactsSubfolder
    System::String dataDir = GetDataDir_Outlook();
    
    // Create three Contacts 
    System::SharedPtr<MapiContact> contact1 = System::MakeObject<MapiContact>(u"Sebastian Wright", u"SebastianWright@dayrep.com");
    System::SharedPtr<MapiContact> contact2 = System::MakeObject<MapiContact>(u"Wichert Kroos", u"WichertKroos@teleworm.us", u"Grade A Investment");
    System::SharedPtr<MapiContact> contact3 = System::MakeObject<MapiContact>(u"Christoffer van de Meeberg", u"ChristoffervandeMeeberg@teleworm.us", u"Krauses Sofa Factory", u"046-630-4614046-630-4614");
    
    // Contact #4
    System::SharedPtr<MapiContact> contact4 = System::MakeObject<MapiContact>();
    contact4->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(u"Margaret", u"J.", u"Tolle"));
    contact4->get_PersonalInfo()->set_Gender(Aspose::Email::Mapi::MapiContactGender::Female);
    contact4->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(u"Adaptaz", u"Recording engineer"));
    contact4->get_PhysicalAddresses()->get_WorkAddress()->set_Address(u"4 Darwinia Loop EIGHTY MILE BEACH WA 6725");
    contact4->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(u"Hisen1988", u"SMTP", u"MargaretJTolle@dayrep.com"));
    contact4->get_Telephones()->set_BusinessTelephoneNumber(u"(08)9080-1183");
    contact4->get_Telephones()->set_MobileTelephoneNumber(u"(925)599-3355(925)599-3355");
    
    // Contact #5
    System::SharedPtr<MapiContact> contact5 = System::MakeObject<MapiContact>();
    contact5->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(u"Matthew", u"R.", u"Wilcox"));
    contact5->get_PersonalInfo()->set_Gender(Aspose::Email::Mapi::MapiContactGender::Male);
    contact5->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(u"Briazz", u"Psychiatric aide"));
    contact5->get_PhysicalAddresses()->get_WorkAddress()->set_Address(u"Horner Strasse 12 4421 SAASS");
    contact5->get_Telephones()->set_BusinessTelephoneNumber(u"0650 675 73 300650 675 73 30");
    contact5->get_Telephones()->set_HomeTelephoneNumber(u"(661)387-5382(661)387-5382");
    
    // Contact #6
    System::SharedPtr<MapiContact> contact6 = System::MakeObject<MapiContact>();
    contact6->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(u"Bertha", u"A.", u"Buell"));
    contact6->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(u"Awthentikz", u"Social work assistant"));
    contact6->get_PersonalInfo()->set_PersonalHomePage(u"B2BTies.com");
    contact6->get_PhysicalAddresses()->get_WorkAddress()->set_Address(u"Im Astenfeld 59 8580 EDELSCHROTT");
    contact6->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(u"Experwas", u"SMTP", u"BerthaABuell@armyspy.com"));
    contact6->set_Telephones(System::MakeObject<MapiContactTelephonePropertySet>(u"06605045265"));
    
    // Load the Outlook file
    System::String path = dataDir + u"SampleContacts_out.pst";
    
    if (System::IO::File::Exists(path))
    {
        System::IO::File::Delete(path);
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"SampleContacts_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> contactFolder = personalStorage->CreatePredefinedFolder(u"Contacts", Aspose::Email::Storage::Pst::StandardIpmFolder::Contacts);
            contactFolder->AddMapiMessageItem(contact1);
            contactFolder->AddMapiMessageItem(contact2);
            contactFolder->AddMapiMessageItem(contact3);
            contactFolder->AddMapiMessageItem(contact4);
            contactFolder->AddMapiMessageItem(contact5);
            contactFolder->AddMapiMessageItem(contact6);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:CreateNewMapiContactAndAddToContactsSubfolder
}

