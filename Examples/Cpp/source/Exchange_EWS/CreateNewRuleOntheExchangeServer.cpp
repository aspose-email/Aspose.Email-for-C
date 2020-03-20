#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/specialized/string_collection.h>
#include <net/network_credential.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Exchange/InboxRules/RulePredicates.h>
#include <Clients/Exchange/InboxRules/RuleActions.h>
#include <Clients/Exchange/InboxRules/InboxRule.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void CreateNewRuleOntheExchangeServer()
{
    // Set Exchange Server 2010 web service URL, Username, password, domain information
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::Console::WriteLine(u"Connected to Exchange server");
    
    System::SharedPtr<InboxRule> rule = System::MakeObject<InboxRule>();
    rule->set_DisplayName(u"Message from client ABC");
    
    // Add conditions
    System::SharedPtr<RulePredicates> newRules = System::MakeObject<RulePredicates>();
    // Set Subject contains string "ABC" and Add the conditions
    newRules->get_ContainsSubjectStrings()->Add(u"ABC");
    newRules->get_FromAddresses()->Add(System::MakeObject<MailAddress>(u"administrator@ex2010.local", true));
    rule->set_Conditions(newRules);
    
    // Add Actions and Move the message to a folder
    System::SharedPtr<RuleActions> newActions = System::MakeObject<RuleActions>();
    newActions->set_MoveToFolder(u"120:AAMkADFjMjNjMmNjLWE3NzgtNGIzNC05OGIyLTAwNTgzNjRhN2EzNgAuAAAAAABbwP+Tkhs0TKx1GMf0D/cPAQD2lptUqri0QqRtJVHwOKJDAAACL5KNAAA=AQAAAA==");
    rule->set_Actions(newActions);

    try 
    {
        client->CreateInboxRule(rule);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
