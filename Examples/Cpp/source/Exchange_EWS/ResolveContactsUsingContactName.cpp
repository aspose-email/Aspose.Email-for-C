#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/console.h>
#include <system/array.h>
#include <PersonalInfo/Contact.h>
#include <Mapi/MapiContactNamePropertySet.h>
#include <Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Mapi/MapiContactElectronicAddress.h>
#include <Mapi/MapiContact.h>
#include <Clients/Exchange/WebService/ExchangeListContactsOptions.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::PersonalInfo;
void ResolveContactsUsingContactName()
{
    try
    {
        // Create instance of IEWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // List all the contacts
        System::ArrayPtr<System::SharedPtr<Contact>> contacts = client->ResolveContacts(u"Changed Name", Aspose::Email::Clients::Exchange::WebService::ExchangeListContactsOptions::FetchPhoto);
        for (System::SharedPtr<Contact> contact : contacts)
        {
            System::SharedPtr<MapiContact> mapiContact = Contact::to_MapiContact(contact);
            // Display name and email address
            System::Console::WriteLine(System::String(u"Name: ") + mapiContact->get_NameInfo()->get_DisplayName() + u", Email Address: " + mapiContact->get_ElectronicAddresses()->get_Email1());
        }
        
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
