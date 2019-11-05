#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <PersonalInfo/URLList.h>
#include <PersonalInfo/UrlCategory.h>
#include <PersonalInfo/Url.h>
#include <PersonalInfo/PhoneNumberList.h>
#include <PersonalInfo/PhoneNumberCategory.h>
#include <PersonalInfo/PhoneNumber.h>
#include <PersonalInfo/Gender.h>
#include <PersonalInfo/EmailAddressList.h>
#include <PersonalInfo/EmailAddressCategory.h>
#include <PersonalInfo/EmailAddress.h>
#include <PersonalInfo/Contact.h>
#include <PersonalInfo/AssociatedPersonsList.h>
#include <PersonalInfo/AssociatedPersonCategory.h>
#include <PersonalInfo/AssociatedPerson.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::PersonalInfo;

void AddContactsToExchangeServerUsingEWS()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    //Create New Contact
    System::SharedPtr<Contact> contact = System::MakeObject<Contact>();
    
    //Set general info
    contact->set_Gender(Aspose::Email::PersonalInfo::Gender::Male);
    contact->set_DisplayName(u"Frank Lin");
    contact->set_CompanyName(u"ABC Co.");
    contact->set_JobTitle(u"Executive Manager");
    
    //Add Phone numbers
    contact->get_PhoneNumbers()->Add([&]{ auto tmp_0 = System::MakeObject<PhoneNumber>(); tmp_0->set_Number(u"123456789"); tmp_0->set_Category(PhoneNumberCategory::get_Home()); return tmp_0; }());
    
    //contact's associated persons
    contact->get_AssociatedPersons()->Add([&]{ auto tmp_1 = System::MakeObject<AssociatedPerson>(); tmp_1->set_Name(u"Catherine"); tmp_1->set_Category(AssociatedPersonCategory::get_Spouse()); return tmp_1; }());
    contact->get_AssociatedPersons()->Add([&]{ auto tmp_2 = System::MakeObject<AssociatedPerson>(); tmp_2->set_Name(u"Bob"); tmp_2->set_Category(AssociatedPersonCategory::get_Child()); return tmp_2; }());
    contact->get_AssociatedPersons()->Add([&]{ auto tmp_3 = System::MakeObject<AssociatedPerson>(); tmp_3->set_Name(u"Merry"); tmp_3->set_Category(AssociatedPersonCategory::get_Sister()); return tmp_3; }());
    
    //URLs
    contact->get_Urls()->Add([&]{ auto tmp_4 = System::MakeObject<Url>(); tmp_4->set_Href(u"www.blog.com"); tmp_4->set_Category(UrlCategory::get_Blog()); return tmp_4; }());
    contact->get_Urls()->Add([&]{ auto tmp_5 = System::MakeObject<Url>(); tmp_5->set_Href(u"www.homepage.com"); tmp_5->set_Category(UrlCategory::get_HomePage()); return tmp_5; }());
    
    //Set contact's Email address
    contact->get_EmailAddresses()->Add([&]{ auto tmp_6 = System::MakeObject<EmailAddress>(); tmp_6->set_Address(u"Frank.Lin@Abc.com"); tmp_6->set_DisplayName(u"Frank Lin"); tmp_6->set_Category(EmailAddressCategory::get_Email1()); return tmp_6; }());
    
    try
    {
        client->CreateContact(contact);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
