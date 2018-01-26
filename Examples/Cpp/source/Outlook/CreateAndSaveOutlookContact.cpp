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
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/array.h>
#include <Formats/Outlook/Mapi/MapiContactTelephonePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactProfessionalPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddress.h>
#include <Formats/Outlook/Mapi/MapiContactPhotoImageFormat.h>
#include <Formats/Outlook/Mapi/MapiContactPhoto.h>
#include <Formats/Outlook/Mapi/MapiContactPersonalInfoPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactOtherPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactNamePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddress.h>
#include <Formats/Outlook/Mapi/MapiContact.h>
#include <Formats/Outlook/Mapi/ContactSaveFormat.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;


void CreateAndSaveOutlookContact()
{
    // ExStart:CreateAndSaveOutlookContact
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiContact> contact = System::MakeObject<MapiContact>();
    contact->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(L"Bertha", L"A.", L"Buell"));
    contact->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(L"Awthentikz", L"Social work assistant"));
    contact->get_PersonalInfo()->set_PersonalHomePage(L"B2BTies.com");
    contact->get_PhysicalAddresses()->get_WorkAddress()->set_Address(L"Im Astenfeld 59 8580 EDELSCHROTT");
    contact->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(L"Experwas", L"SMTP", L"BerthaABuell@armyspy.com"));
    contact->set_Telephones(System::MakeObject<MapiContactTelephonePropertySet>(L"06605045265"));
    contact->get_PersonalInfo()->set_Children(System::MakeArray<System::String>({L"child1", L"child2", L"child3"}));
    contact->set_Categories(System::MakeArray<System::String>({L"category1", L"category2", L"category3"}));
    contact->set_Mileage(L"Some test mileage");
    contact->set_Billing(L"Test billing information");
    contact->get_OtherFields()->set_Journal(true);
    contact->get_OtherFields()->set_Private(true);
    contact->get_OtherFields()->set_ReminderTime(System::DateTime(2014, 1, 1, 0, 0, 55));
    contact->get_OtherFields()->set_ReminderTopic(L"Test topic");
    contact->get_OtherFields()->set_UserField1(L"ContactUserField1");
    contact->get_OtherFields()->set_UserField2(L"ContactUserField2");
    contact->get_OtherFields()->set_UserField3(L"ContactUserField3");
    contact->get_OtherFields()->set_UserField4(L"ContactUserField4");
    
    // Add a photo
    {
        System::SharedPtr<System::IO::FileStream> fs = System::IO::File::OpenRead(dataDir + L"Desert.jpg");
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ fs, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::ArrayPtr<uint8_t> buffer = System::MakeArray<uint8_t>(fs->get_Length(), 0);
        fs->Read(buffer, 0, buffer->get_Length());
        contact->set_Photo(System::MakeObject<MapiContactPhoto>(buffer, Aspose::Email::Outlook::MapiContactPhotoImageFormat::Jpeg));
    }
    // Save the Contact in MSG format
    contact->Save(dataDir + L"MapiContact_out.msg", Aspose::Email::Outlook::ContactSaveFormat::Msg);
    
    // Save the Contact in VCF format
    contact->Save(dataDir + L"MapiContact_out.vcf", Aspose::Email::Outlook::ContactSaveFormat::VCard);
    // ExEnd:CreateAndSaveOutlookContact
}







