#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <Calendar/TaskCollection.h>


using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Exchange::WebService;
void SpecifyTimeZoneForExchange()
{
    try
    {
        // Set mailboxURI, Username, password, domain information
        System::String mailboxUri = u"https://ex2010/ews/exchange.asmx";
        System::String username = u"test.exchange";
        System::String password = u"pwd";
        System::String domain = u"ex2010.local";
        System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        client->set_TimezoneId(u"Central Europe Standard Time");
        
        // Listing Tasks from Server
        System::SharedPtr<TaskCollection> taskCollection = client->ListTasks(client->get_MailboxInfo()->get_TasksUri());
        
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
