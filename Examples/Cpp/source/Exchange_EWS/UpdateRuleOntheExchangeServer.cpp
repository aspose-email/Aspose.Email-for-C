#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <net/network_credential.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/InboxRules/RulePredicates.h>
#include <Clients/Exchange/InboxRules/InboxRule.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void UpdateRuleOntheExchangeServer()
{
    
    try
    {
        
        // Set mailboxURI, Username, password, domain information
        System::String mailboxURI = u"https://ex2010/ews/exchange.asmx";
        System::String username = u"test.exchange";
        System::String password = u"pwd";
        System::String domain = u"ex2010.local";
        
        // Connect to the Exchange Server
        System::SharedPtr<System::Net::NetworkCredential> credential = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        System::Console::WriteLine(u"Connected to Exchange server");
        
        // Get all Inbox Rules
        System::ArrayPtr<System::SharedPtr<InboxRule>> inboxRules = client->GetInboxRules();
        
        // Loop through each rule
        for (System::SharedPtr<InboxRule> inboxRule : inboxRules)
        {
            System::Console::WriteLine(System::String(u"Display Name: ") + inboxRule->get_DisplayName());
            if (inboxRule->get_DisplayName() == u"Message from client ABC")
            {
                System::Console::WriteLine(u"Updating the rule....");
                inboxRule->get_Conditions()->get_FromAddresses()->idx_set(0, System::MakeObject<MailAddress>(u"administrator@ex2010.local", true));
                client->UpdateInboxRule(inboxRule);
            }
        }
        
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex->get_Message());
    }
    
}
