#include "Examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

void ConnectingToExchangeServerUsingEWS()
{
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::Console::WriteLine(client->ListMessages(u"Inbox")->get_Count());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}

