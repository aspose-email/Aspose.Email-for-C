#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/BoolComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/Search/ExchangeAdvancedSyntaxQueryBuilder.h>
#include <Clients/Exchange/Search/ExchangeAdvancedSyntaxMailQuery.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;

void AdvancedSyntaxQueryBuilderUsingEWS()
{
    // Connect to EWS
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String username = u"username";
    const System::String password = u"password";
    const System::String domain = u"domain";
    
    //ExStart: FilterAppointmentsByDateUsingEWS
    System::SharedPtr<IEWSClient> client = EWSClient::GetEWSClient(mailboxUri, username, password, domain);
    
    // Create a search query using query builder
    System::SharedPtr<ExchangeAdvancedSyntaxQueryBuilder> advancedBuilder = System::MakeObject<ExchangeAdvancedSyntaxQueryBuilder>();
    advancedBuilder->get_From()->Equals(u"Jim Martin");
    advancedBuilder->get_Subject()->Contains(u"report");
    advancedBuilder->get_HasAttachment()->Equals(true);
    System::SharedPtr<ExchangeMessageInfoCollection> messages = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), advancedBuilder->GetQuery());
    
    // Сreate a search query directly by using AQS
    System::SharedPtr<ExchangeAdvancedSyntaxMailQuery> query = System::MakeObject<ExchangeAdvancedSyntaxMailQuery>(u"subject:(product AND report)");
    System::SharedPtr<ExchangeMessageInfoCollection> messages2 = client->ListMessages(client->get_MailboxInfo()->get_InboxUri(), query);
}
