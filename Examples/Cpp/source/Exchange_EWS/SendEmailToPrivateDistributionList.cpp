#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <net/network_credential.h>
#include <MailMessage.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
void SendEmailToPrivateDistributionList()
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
        
        
        System::ArrayPtr<System::SharedPtr<ExchangeDistributionList>> distributionLists = client->ListDistributionLists();
        System::SharedPtr<MailAddress> distributionListAddress = distributionLists[0]->ToMailAddress();
        System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(System::MakeObject<MailAddress>(u"from@host.com"), distributionListAddress);
        message->set_Subject(u"sendToPrivateDistributionList");
        client->Send(message);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
