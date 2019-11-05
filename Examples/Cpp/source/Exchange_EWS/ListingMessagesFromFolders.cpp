#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void ListingMessagesFromFolders()
{
    try
    {
        // Create instance of EWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Get folder URI
        System::String strFolderURI = System::String::Empty;
        strFolderURI = client->get_MailboxInfo()->get_InboxUri();
        strFolderURI = client->get_MailboxInfo()->get_DeletedItemsUri();
        strFolderURI = client->get_MailboxInfo()->get_DraftsUri();
        strFolderURI = client->get_MailboxInfo()->get_SentItemsUri();
        
        // Get list of messages from the specified folder
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(strFolderURI);
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex.get_Message());
    }
    
}
