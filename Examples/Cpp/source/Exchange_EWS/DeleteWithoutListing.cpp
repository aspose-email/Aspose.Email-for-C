#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeDistributionList.h>

using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void DeleteWithoutListing()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::SharedPtr<ExchangeDistributionList> distributionList = System::MakeObject<ExchangeDistributionList>();
    distributionList->set_Id(u"list's id");
    try 
    {
        client->DeleteDistributionList(distributionList, true);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}
