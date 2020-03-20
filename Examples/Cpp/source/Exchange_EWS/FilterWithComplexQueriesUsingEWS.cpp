#include "Examples.h"
#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQueryBuilder.h>
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
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Tools::Search;
void FilterWithComplexQueriesUsingEWS()
{
    // Connect to EWS
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String username = u"username";
    const System::String password = u"password";
    const System::String domain = u"domain";
    
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
        
        // Emails from specific host, get all emails that arrived before today and all emails that arrived since 7 days ago
        builder->get_From()->Contains(u"SpecificHost.com");
        builder->get_InternalDate()->Before(System::DateTime::get_Now());
        builder->get_InternalDate()->Since(System::DateTime::get_Now().AddDays(-7));
        
        // Build the query and Get list of messages
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<ExchangeMessageInfoCollection> messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        builder->Or(builder->get_Subject()->Contains(u"test"), builder->get_From()->Contains(u"noreply@host.com"));
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
