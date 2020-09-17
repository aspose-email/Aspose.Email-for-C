#include "Examples.h"
#include <system/shared_ptr.h>
#include <system/array.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void DeletePrivateDistributionList()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    try 
    {
        System::ArrayPtr<System::SharedPtr<ExchangeDistributionList>> distributionLists = client->ListDistributionLists();
        client->DeleteDistributionList(distributionLists[0], true);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
