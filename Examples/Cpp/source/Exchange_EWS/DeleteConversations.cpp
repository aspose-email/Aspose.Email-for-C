#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/array.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/WebService/Conversation/ExchangeConversation.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>

using namespace Aspose::Email::Clients::Exchange::WebService;

void DeleteConversations()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange 2010");

    try 
    {
        // Find those Conversation Items in the Inbox folder which we want to delete
        System::ArrayPtr<System::SharedPtr<ExchangeConversation>> conversations = client->FindConversations(client->get_MailboxInfo()->get_InboxUri());
        for (System::SharedPtr<ExchangeConversation> conversation : conversations)
        {
            System::Console::WriteLine(System::String(u"Topic: ") + conversation->get_ConversationTopic());
            // Delete the conversation item based on some condition
            if (conversation->get_ConversationTopic().Contains(u"test email") == true)
            {
                client->DeleteConversationItems(conversation->get_ConversationId());
                System::Console::WriteLine(u"Deleted the conversation item");
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

    
}
