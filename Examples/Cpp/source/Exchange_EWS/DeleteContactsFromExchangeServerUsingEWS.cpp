#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <PersonalInfo/Contact.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::PersonalInfo;
void DeleteContactsFromExchangeServerUsingEWS()
{
    try
    {
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        System::String strContactToDelete = u"John Teddy";
        System::ArrayPtr<System::SharedPtr<Contact>> contacts = client->GetContacts(client->get_MailboxInfo()->get_ContactsUri());
        for (System::SharedPtr<Contact> contact : contacts)
        {
            if (System::ObjectExt::Equals(contact->get_DisplayName(), strContactToDelete))
            {
                client->DeleteContact(contact);
            }
        }
        
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
