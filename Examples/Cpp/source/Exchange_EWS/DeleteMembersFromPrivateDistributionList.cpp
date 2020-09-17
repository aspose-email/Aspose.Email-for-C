#include "Examples.h"
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/array.h>
#include <system/console.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void DeleteMembersFromPrivateDistributionList()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    try 
    {
        System::ArrayPtr<System::SharedPtr<ExchangeDistributionList>> distributionLists = client->ListDistributionLists();
        System::SharedPtr<MailAddressCollection> members = client->FetchDistributionList(distributionLists[0]);
        System::SharedPtr<MailAddressCollection> membersToDelete = System::MakeObject<MailAddressCollection>();
        membersToDelete->Add(members->idx_get(0));
        membersToDelete->Add(members->idx_get(1));
        client->DeleteFromDistributionList(distributionLists[0], membersToDelete);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
