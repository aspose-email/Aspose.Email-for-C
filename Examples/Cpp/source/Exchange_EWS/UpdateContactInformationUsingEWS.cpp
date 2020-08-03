#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <PersonalInfo/Contact.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::PersonalInfo;
void UpdateContactInformationUsingEWS()
{
    try
    {
        System::String mailboxUri = u"https://ex2010/ews/exchange.asmx";
        System::String username = u"test.exchange";
        System::String password = u"pwd";
        System::String domain = u"ex2010.local";
        System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
        
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // List all the contacts and Loop through all contacts
        System::ArrayPtr<System::SharedPtr<Contact>> contacts = client->GetContacts(client->get_MailboxInfo()->get_ContactsUri());
        System::SharedPtr<Contact> contact = contacts[0];
        System::Console::WriteLine(System::String(u"Name: ") + contact->get_DisplayName());
        contact->set_DisplayName(u"David Ch");
        client->UpdateContact(contact);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
