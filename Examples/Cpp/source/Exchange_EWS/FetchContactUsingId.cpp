#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <PersonalInfo/Contact.h>
#include <ObjectIdentifier.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::PersonalInfo;
void FetchContactUsingId()
{
    try
    {
        // Create instance of IEWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::String id = client->GetContacts(client->get_MailboxInfo()->get_ContactsUri())->idx_get(0)->get_Id()->get_EWSId();
        
        
        System::SharedPtr<Contact> fetchedContact = client->GetContact(id);
        
        System::Console::WriteLine(System::String(u"Name: ") + fetchedContact->get_DisplayName());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
