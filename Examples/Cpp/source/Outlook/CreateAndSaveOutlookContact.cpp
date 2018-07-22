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
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/array.h>
#include <Mapi/MapiContactTelephonePropertySet.h>
#include <Mapi/MapiContactProfessionalPropertySet.h>
#include <Mapi/MapiContactPhysicalAddressPropertySet.h>
#include <Mapi/MapiContactPhysicalAddress.h>
#include <Mapi/MapiContactPhotoImageFormat.h>
#include <Mapi/MapiContactPhoto.h>
#include <Mapi/MapiContactPersonalInfoPropertySet.h>
#include <Mapi/MapiContactOtherPropertySet.h>
#include <Mapi/MapiContactNamePropertySet.h>
#include <Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Mapi/MapiContactElectronicAddress.h>
#include <Mapi/MapiContact.h>
#include <Mapi/ContactSaveFormat.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void CreateAndSaveOutlookContact()
{
    // ExStart:CreateAndSaveOutlookContact
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiContact> contact = System::MakeObject<MapiContact>();
    contact->set_NameInfo(System::MakeObject<MapiContactNamePropertySet>(u"Bertha", u"A.", u"Buell"));
    contact->set_ProfessionalInfo(System::MakeObject<MapiContactProfessionalPropertySet>(u"Awthentikz", u"Social work assistant"));
    contact->get_PersonalInfo()->set_PersonalHomePage(u"B2BTies.com");
    contact->get_PhysicalAddresses()->get_WorkAddress()->set_Address(u"Im Astenfeld 59 8580 EDELSCHROTT");
    contact->get_ElectronicAddresses()->set_Email1(System::MakeObject<MapiContactElectronicAddress>(u"Experwas", u"SMTP", u"BerthaABuell@armyspy.com"));
    contact->set_Telephones(System::MakeObject<MapiContactTelephonePropertySet>(u"06605045265"));
    contact->get_PersonalInfo()->set_Children(System::MakeArray<System::String>({u"child1", u"child2", u"child3"}));
    contact->set_Categories(System::MakeArray<System::String>({u"category1", u"category2", u"category3"}));
    contact->set_Mileage(u"Some test mileage");
    contact->set_Billing(u"Test billing information");
    contact->get_OtherFields()->set_Journal(true);
    contact->get_OtherFields()->set_Private(true);
    contact->get_OtherFields()->set_ReminderTime(System::DateTime(2014, 1, 1, 0, 0, 55));
    contact->get_OtherFields()->set_ReminderTopic(u"Test topic");
    contact->get_OtherFields()->set_UserField1(u"ContactUserField1");
    contact->get_OtherFields()->set_UserField2(u"ContactUserField2");
    contact->get_OtherFields()->set_UserField3(u"ContactUserField3");
    contact->get_OtherFields()->set_UserField4(u"ContactUserField4");
    
    // Add a photo
    {
        System::SharedPtr<System::IO::FileStream> fs = System::IO::File::OpenRead(dataDir + u"Desert.jpg");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ fs});
        // ------------------------------------------
        
        try
        {
            System::ArrayPtr<uint8_t> buffer = System::MakeArray<uint8_t>(fs->get_Length(), 0);
            fs->Read(buffer, 0, buffer->get_Length());
            contact->set_Photo(System::MakeObject<MapiContactPhoto>(buffer, Aspose::Email::Mapi::MapiContactPhotoImageFormat::Jpeg));
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // Save the Contact in MSG format
    contact->Save(dataDir + u"MapiContact_out.msg", Aspose::Email::Mapi::ContactSaveFormat::Msg);
    
    // Save the Contact in VCF format
    contact->Save(dataDir + u"MapiContact_out.vcf", Aspose::Email::Mapi::ContactSaveFormat::VCard);
    // ExEnd:CreateAndSaveOutlookContact
}

