#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void DeleteMembersWithoutListing()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::SharedPtr<ExchangeDistributionList> distributionList = System::MakeObject<ExchangeDistributionList>();
    distributionList->set_Id(u"list's id");
    distributionList->set_ChangeKey(u"list's change key");
    System::SharedPtr<MailAddressCollection> membersToDelete = System::MakeObject<MailAddressCollection>();
    System::SharedPtr<MailAddress> addressToDelete = System::MakeObject<MailAddress>(u"address", true);
    //addressToDelete.Id.EWSId = "member's id";
    membersToDelete->Add(addressToDelete);
    try 
    {
        client->AddToDistributionList(distributionList, membersToDelete);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
