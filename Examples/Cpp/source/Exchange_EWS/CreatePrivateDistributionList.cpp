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
void CreatePrivateDistributionList()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::SharedPtr<ExchangeDistributionList> distributionList = System::MakeObject<ExchangeDistributionList>();
    distributionList->set_DisplayName(u"test private list");
    System::SharedPtr<MailAddressCollection> members = System::MakeObject<MailAddressCollection>();
    members->Add(u"address1@host.com");
    members->Add(u"address2@host.com");
    members->Add(u"address3@host.com");
    try 
    {
        client->CreateDistributionList(distributionList, members);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}
