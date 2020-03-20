#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/nullable.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <PersonalInfo/URLList.h>
#include <PersonalInfo/PostalAddressList.h>
#include <PersonalInfo/PostalAddressCategory.h>
#include <PersonalInfo/PostalAddress.h>
#include <PersonalInfo/PhoneNumberList.h>
#include <PersonalInfo/PhoneNumberCategory.h>
#include <PersonalInfo/PhoneNumber.h>
#include <PersonalInfo/InstantMessengerList.h>
#include <PersonalInfo/EventList.h>
#include <PersonalInfo/EmailAddressList.h>
#include <PersonalInfo/EmailAddress.h>
#include <PersonalInfo/Contact.h>
#include <PersonalInfo/AssociatedPersonsList.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Clients::Google;
using namespace Aspose::Email::PersonalInfo;

void CreateGmailContact()
{
    try
    {
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        // Gmail Client
        System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
        
        // Create a Contact
        System::SharedPtr<Contact> contact = System::MakeObject<Contact>();
        contact->set_Prefix(u"Prefix");
        contact->set_GivenName(u"GivenName");
        contact->set_Surname(u"Surname");
        contact->set_MiddleName(u"MiddleName");
        contact->set_DisplayName(u"Test User 1");
        contact->set_Suffix(u"Suffix");
        contact->set_JobTitle(u"JobTitle");
        contact->set_DepartmentName(u"DepartmentName");
        contact->set_CompanyName(u"CompanyName");
        contact->set_Profession(u"Profession");
        contact->set_Notes(u"Notes");
        System::SharedPtr<PostalAddress> address = System::MakeObject<PostalAddress>();
        address->set_Category(PostalAddressCategory::get_Work());
        address->set_Address(u"Address");
        address->set_Street(u"Street");
        address->set_PostOfficeBox(u"PostOfficeBox");
        address->set_City(u"City");
        address->set_StateOrProvince(u"StateOrProvince");
        address->set_PostalCode(u"PostalCode");
        address->set_Country(u"Country");
        contact->get_PhysicalAddresses()->Add(address);
        System::SharedPtr<PhoneNumber> pnWork = System::MakeObject<PhoneNumber>();
        pnWork->set_Number(u"323423423423");
        pnWork->set_Category(PhoneNumberCategory::get_Work());
        contact->get_PhoneNumbers()->Add(pnWork);
        System::SharedPtr<PhoneNumber> pnHome = System::MakeObject<PhoneNumber>();
        pnHome->set_Number(u"323423423423");
        pnHome->set_Category(PhoneNumberCategory::get_Home());
        contact->get_PhoneNumbers()->Add(pnHome);
        System::SharedPtr<PhoneNumber> pnMobile = System::MakeObject<PhoneNumber>();
        pnMobile->set_Number(u"323423423423");
        pnMobile->set_Category(PhoneNumberCategory::get_Mobile());
        contact->get_PhoneNumbers()->Add(pnMobile);
        contact->get_Urls()->set_Blog(u"Blog.ru");
        contact->get_Urls()->set_BusinessHomePage(u"BusinessHomePage.ru");
        contact->get_Urls()->set_HomePage(u"HomePage.ru");
        contact->get_Urls()->set_Profile(u"Profile.ru");
        contact->get_Events()->set_Birthday(System::DateTime::get_Now().AddYears(-30));
        contact->get_Events()->set_Anniversary(System::DateTime::get_Now().AddYears(-10));
        contact->get_InstantMessengers()->set_AIM(u"AIM");
        contact->get_InstantMessengers()->set_GoogleTalk(u"GoogleTalk");
        contact->get_InstantMessengers()->set_ICQ(u"ICQ");
        contact->get_InstantMessengers()->set_Jabber(u"Jabber");
        contact->get_InstantMessengers()->set_MSN(u"MSN");
        contact->get_InstantMessengers()->set_QQ(u"QQ");
        contact->get_InstantMessengers()->set_Skype(u"Skype");
        contact->get_InstantMessengers()->set_Yahoo(u"Yahoo");
        contact->get_AssociatedPersons()->set_Spouse(u"Spouse");
        contact->get_AssociatedPersons()->set_Sister(u"Sister");
        contact->get_AssociatedPersons()->set_Relative(u"Relative");
        contact->get_AssociatedPersons()->set_ReferredBy(u"ReferredBy");
        contact->get_AssociatedPersons()->set_Partner(u"Partner");
        contact->get_AssociatedPersons()->set_Parent(u"Parent");
        contact->get_AssociatedPersons()->set_Mother(u"Mother");
        contact->get_AssociatedPersons()->set_Manager(u"Manager");
        
        // Email Address
        System::SharedPtr<EmailAddress> eAddress = System::MakeObject<EmailAddress>();
        eAddress->set_Address(u"email@gmail.com");
        contact->get_EmailAddresses()->Add(eAddress);
        System::String contactUri = client->CreateContact(contact);
        // ExEnd:CreateGmailContact
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
