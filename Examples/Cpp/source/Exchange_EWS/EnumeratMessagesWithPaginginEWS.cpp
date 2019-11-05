#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <cstdint>
#include <Clients/PageInfo.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessagePageInfo.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients;
void EnumeratMessagesWithPaginginEWS()
{
    
    {
        auto __finally_guard_0 = ::System::MakeScopeGuard([=]() { });
        
        try
        {
            // Create instance of ExchangeWebServiceClient class by giving credentials
            System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
            
            // Call ListMessages method to list messages info from Inbox
            System::SharedPtr<ExchangeMessageInfoCollection> msgCollection = client->ListMessages(client->GetMailboxInfo()->get_InboxUri());
            int32_t itemsPerPage = 5;
            System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<PageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<PageInfo>>>();
            System::SharedPtr<PageInfo> pagedMessageInfoCol = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), itemsPerPage);
            pages->Add(pagedMessageInfoCol);
            while (!pagedMessageInfoCol->get_LastPage())
            {
                pagedMessageInfoCol = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), itemsPerPage);
                pages->Add(pagedMessageInfoCol);
            }
            pagedMessageInfoCol = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), itemsPerPage);
            while (!pagedMessageInfoCol->get_LastPage())
            {
                client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
            }
        }
        catch (System::Exception& ex)
        {
            
            System::Console::Write(ex.get_Message());
        }
    }
}
