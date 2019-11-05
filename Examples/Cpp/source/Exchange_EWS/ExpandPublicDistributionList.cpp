#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
void ExpandPublicDistributionList()
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
        
        
        System::SharedPtr<MailAddressCollection> members = client->ExpandDistributionList(System::MakeObject<MailAddress>(u"public.distribution.list@host.com"));
        for (auto member : System::IterateOver(members))
        {
            System::Console::WriteLine(member->get_Address());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
