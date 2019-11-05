#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void FetchPrivateDistributionList()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    try 
    {
        System::ArrayPtr<System::SharedPtr<ExchangeDistributionList>> distributionLists = client->ListDistributionLists();
        for (System::SharedPtr<ExchangeDistributionList> distributionList : distributionLists)
        {
            System::SharedPtr<MailAddressCollection> members = client->FetchDistributionList(distributionList);
            for (auto member : System::IterateOver(members))
            {
                System::Console::WriteLine(member->get_Address());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
}
