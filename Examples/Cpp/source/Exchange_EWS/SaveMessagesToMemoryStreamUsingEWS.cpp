#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void SaveMessagesToMemoryStreamUsingEWS()
{
    
    try
    {
        System::String datadir = GetDataDir_Exchange();
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Call ListMessages method to list messages info from Inbox
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        // Loop through the collection to get Message URI
        for (auto msgInfo : System::IterateOver(msgCollection))
        {
            System::String strMessageURI = msgInfo->get_UniqueUri();
            
            // Now save the message in memory stream
            System::SharedPtr<System::IO::MemoryStream> stream = System::MakeObject<System::IO::MemoryStream>();
            client->SaveMessage(strMessageURI, datadir + stream);
        }
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex->get_Message());
    }
    
}
