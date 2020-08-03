#include "Examples.h"
#include <system/enumerator_adapter.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessagePageInfo.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void PagingSupportForListingMessages()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    // Clearing resources under 'using' statement

    // Create some test messages to be added to server for retrieval later
    int32_t messagesNum = 12;
    int32_t itemsPerPage = 5;
    System::SharedPtr<MailMessage> message;
    for (int32_t i = 0; i < messagesNum; i++)
    {
        message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-35157_1 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-35157 Move paging parameters to separate class");
        client->AppendMessage(client->get_MailboxInfo()->get_InboxUri(), message);
    }
    // Verfiy that the messages have been added to the server
    System::SharedPtr<ExchangeMessageInfoCollection> totalMessageInfoCol = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
    System::Console::WriteLine(totalMessageInfoCol->get_Count());

    /// /////////////// RETREIVING THE MESSAGES USING PAGING SUPPORT ////////////////////////////////////

    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<ExchangeMessagePageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<ExchangeMessagePageInfo>>>();
    System::SharedPtr<ExchangeMessagePageInfo> pageInfo = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), itemsPerPage);
    // Total Pages Count
    System::Console::WriteLine(pageInfo->get_TotalCount());

    pages->Add(pageInfo);
    while (!pageInfo->get_LastPage())
    {
        pageInfo = client->ListMessagesByPage(client->get_MailboxInfo()->get_InboxUri(), itemsPerPage, pageInfo->get_PageOffset() + 1);
        pages->Add(pageInfo);
    }
    int32_t retrievedItems = 0;
    for (auto pageCol : System::IterateOver(pages))
    {
        retrievedItems += pageCol->get_Items()->get_Count();
    }
    // Verify total message count using paging
    System::Console::WriteLine(retrievedItems);
}
