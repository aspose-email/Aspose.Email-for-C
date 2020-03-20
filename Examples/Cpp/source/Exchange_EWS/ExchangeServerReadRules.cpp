#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/specialized/string_collection.h>
#include <system/array.h>
#include <net/network_credential.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Exchange/InboxRules/RulePredicates.h>
#include <Clients/Exchange/InboxRules/RuleActions.h>
#include <Clients/Exchange/InboxRules/InboxRule.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void ExchangeServerReadRules()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::Console::WriteLine(u"Connected to Exchange server");

    try 
    {
        // Get all Inbox Rules
        System::ArrayPtr<System::SharedPtr<InboxRule>> inboxRules = client->GetInboxRules();
    
        // Display information about each rule
        for (System::SharedPtr<InboxRule> inboxRule : inboxRules)
        {
            System::Console::WriteLine(System::String(u"Display Name: ") + inboxRule->get_DisplayName());
        
            // Check if there is a "From Address" condition
            if (inboxRule->get_Conditions()->get_FromAddresses()->get_Count() > 0)
            {
                for (auto fromAddress : System::IterateOver(inboxRule->get_Conditions()->get_FromAddresses()))
                {
                    System::Console::WriteLine(System::String(u"From: ") + fromAddress->get_DisplayName() + u" - " + fromAddress->get_Address());
                }
            }
            // Check if there is a "Subject Contains" condition
            if (inboxRule->get_Conditions()->get_ContainsSubjectStrings()->get_Count() > 0)
            {
                for (auto subject : System::IterateOver(inboxRule->get_Conditions()->get_ContainsSubjectStrings()))
                {
                    System::Console::WriteLine(System::String(u"Subject contains: ") + subject);
                }
            }
            // Check if there is a "Move to Folder" action
            if (inboxRule->get_Actions()->get_MoveToFolder().get_Length() > 0)
            {
                System::Console::WriteLine(System::String(u"Move message to folder: ") + inboxRule->get_Actions()->get_MoveToFolder());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}
