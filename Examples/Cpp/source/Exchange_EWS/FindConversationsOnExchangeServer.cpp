#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/array.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/WebService/Conversation/ExchangeConversationFlagStatus.h>
#include <Clients/Exchange/WebService/Conversation/ExchangeConversation.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

void FindConversationsOnExchangeServer()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange 2010");

    try 
    {
        // Find Conversation Items in the Inbox folder
        System::ArrayPtr<System::SharedPtr<ExchangeConversation>> conversations = client->FindConversations(client->get_MailboxInfo()->get_InboxUri());
        // Show all conversations
        for (System::SharedPtr<ExchangeConversation> conversation : conversations)
        {
            // Display conversation properties like Id and Topic
            System::Console::WriteLine(System::String(u"Topic: ") + conversation->get_ConversationTopic());
            System::Console::WriteLine(System::String(u"Flag Status: ") + System::ObjectExt::ToString(conversation->get_FlagStatus()));
            System::Console::WriteLine();
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
