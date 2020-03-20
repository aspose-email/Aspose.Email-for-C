#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <MailAddressCollection.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void AddMembersWithoutListing()
{
    try 
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::SharedPtr<ExchangeDistributionList> distributionList = System::MakeObject<ExchangeDistributionList>();
        distributionList->set_Id(u"list's id");
        distributionList->set_ChangeKey(u"list's change key");
        System::SharedPtr<MailAddressCollection> newMembers = System::MakeObject<MailAddressCollection>();
        newMembers->Add(u"address6@host.com");
        client->AddToDistributionList(distributionList, newMembers);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}
