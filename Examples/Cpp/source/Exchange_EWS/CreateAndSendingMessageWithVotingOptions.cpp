#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mapi/FollowUpOptions.h>
#include <MailMessage.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Clients::Exchange::WebService;

System::SharedPtr<MailMessage> CreateTestMessage(System::String address)
{
    System::SharedPtr<MailMessage> eml = System::MakeObject<MailMessage>(address, address, u"Flagged message", u"Make it nice and short, but descriptive. The description may appear in search engines' search results pages...");

    return eml;
}

void CreateAndSendingMessageWithVotingOptions()
{
    System::String address = u"firstname.lastname@aspose.com";
    
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::SharedPtr<MailMessage> message = CreateTestMessage(address);
    
    // Set FollowUpOptions Buttons
    System::SharedPtr<FollowUpOptions> options = System::MakeObject<FollowUpOptions>();
    options->set_VotingButtons(u"Yes;No;Maybe;Exactly!");
    
    try 
    {
        client->Send(message, options);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

}

