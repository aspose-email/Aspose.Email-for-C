#include "Examples.h"
#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQueryBuilder.h>
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/IntComparisonField.h>
#include <Tools/Search/DateComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/Search/ExchangeQueryBuilder.h>
#include <Clients/Exchange/ExchangeMessagePageInfo.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <Clients/Exchange/Dav/ContentClassType.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::Dav;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Tools::Search;

void FilterMessagesWithPagingSupport()
{
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String username = u"username";
    const System::String password = u"password";
    const System::String domain = u"domain";

    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    int32_t itemsPerPage = 5;
    System::String sGuid = System::ObjectExt::ToString(System::Guid::NewGuid());
    System::String str1 = sGuid + u" - " + u"Query 1";
    System::String str2 = sGuid + u" - " + u"Query 2";

    System::SharedPtr<MailQueryBuilder> queryBuilder1 = System::MakeObject<MailQueryBuilder>();
    queryBuilder1->get_Subject()->Contains(str1);
    System::SharedPtr<MailQuery> query1 = queryBuilder1->GetQuery();
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<ExchangeMessagePageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<ExchangeMessagePageInfo>>>();
    System::SharedPtr<ExchangeMessagePageInfo> pageInfo = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), query1, itemsPerPage);
    pages->Add(pageInfo);
    int32_t str1Count = pageInfo->get_Items()->get_Count();
    while (!pageInfo->get_LastPage())
    {
        pageInfo = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), query1, itemsPerPage, pageInfo->get_PageOffset() + 1);
        pages->Add(pageInfo);
        str1Count += pageInfo->get_Items()->get_Count();
    }
}


void FilterMessagesOnCriteriaUsingEWS()
{
    // Connect to EWS
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String username = u"username";
    const System::String password = u"password";
    const System::String domain = u"domain";
    
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Emails that arrived today
        System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
        builder->get_InternalDate()->On(System::DateTime::get_Now());
        
        // Build the query and Get list of messages
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<ExchangeMessageInfoCollection> messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // Emails that arrived in last 7 days
        builder->get_InternalDate()->Before(System::DateTime::get_Now());
        builder->get_InternalDate()->Since(System::DateTime::get_Now().AddDays(-7));
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // Get emails from specific sender
        builder->get_From()->Contains(u"saqib.razzaq@127.0.0.1");
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // Get emails from specific domain
        builder->get_From()->Contains(u"SpecificHost.com");
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // Get emails sent to specific recipient
        builder->get_To()->Contains(u"recipient");
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        // Get email with specific MessageId
        System::SharedPtr<ExchangeQueryBuilder> builder1 = System::MakeObject<ExchangeQueryBuilder>();
        builder1->get_MessageId()->Equals(u"MessageID");
        
        // Build the query and Get list of messages
        query = builder1->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
        // Get Mail Delivery Notifications
        builder1 = System::MakeObject<ExchangeQueryBuilder>();
        builder1->get_ContentClass()->Equals(System::ObjectExt::ToString(ContentClassType::get_MDN()));
        
        builder1 = System::MakeObject<ExchangeQueryBuilder>();
        builder1->get_ItemSize()->Greater(80000);
        
        // Build the query and Get list of messages
        query = builder1->GetQuery();
        messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
        System::Console::WriteLine(System::String(u"EWS: ") + messages->get_Count() + u" message(s) found.");
        
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}

