#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

#include "Examples.h"


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void SaveMessagesUsingExchangeWebServices()
{
    try
    {
        System::String dataDir = GetDataDir_Exchange();
        // Create instance of IEWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Call ListMessages method to list messages info from Inbox
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        // Loop through the collection to get Message URI
        for (auto msgInfo : System::IterateOver(msgCollection))
        {
            System::String strMessageURI = msgInfo->get_UniqueUri();
            
            // Now save the message in disk
            client->SaveMessage(strMessageURI, dataDir + msgInfo->get_MessageId() + u"out.eml");
        }
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex.get_Message());
    }
    
    
}
