#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void ListingMessagesUsingEWS()
{
    try
    {
        // Create instance of ExchangeWebServiceClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Call ListMessages method to list messages info from Inbox
        System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        // Loop through the collection to display the basic information
        for (auto msgInfo : System::IterateOver(msgCollection))
        {
            System::Console::WriteLine(System::String(u"Subject: ") + msgInfo->get_Subject());
            if (msgInfo->get_From() != nullptr)
                System::Console::WriteLine(System::String(u"From: ") + msgInfo->get_From()->ToString());
            System::Console::WriteLine(System::String(u"To: ") + msgInfo->get_To()->ToString());
            System::Console::WriteLine(System::String(u"Message ID: ") + msgInfo->get_MessageId());
            System::Console::WriteLine(System::String(u"Unique URI: ") + msgInfo->get_UniqueUri());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
    }
    
}
