#include "Examples.h"
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void AddMembersToPrivateDistributionList()
{
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::ArrayPtr<System::SharedPtr<ExchangeDistributionList>> distributionLists = client->ListDistributionLists();
        System::SharedPtr<MailAddressCollection> newMembers = System::MakeObject<MailAddressCollection>();
        newMembers->Add(u"address4@host.com");
        newMembers->Add(u"address5@host.com");
        client->AddToDistributionList(distributionLists[0], newMembers);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
}
