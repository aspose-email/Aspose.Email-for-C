#include "Examples.h"
#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/DateComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/Search/ExchangeQueryBuilder.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Tools::Search;
void FilterMessagesUsingEWS()
{
    try
    {
        // Connect to EWS
        const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
        const System::String username = u"username";
        const System::String password = u"password";
        const System::String domain = u"domain";
        
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Query building by means of ExchangeQueryBuilder class
        System::SharedPtr<ExchangeQueryBuilder> builder = System::MakeObject<ExchangeQueryBuilder>();
        
        // Set Subject and Emails that arrived today
        builder->get_Subject()->Contains(u"Newsletter");
        builder->get_InternalDate()->On(System::DateTime::get_Now());
        
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        
        // Get list of messages
        System::SharedPtr<ExchangeMessageInfoCollection> messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query, false);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        // Disconnect from EWS
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
