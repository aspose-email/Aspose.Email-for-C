#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void CreateREAndFWMessages()
{
    System::String dataDir = GetDataDir_Exchange();
    
    const System::String mailboxUri = u"https://exchange.domain.com/ews/Exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username";
    const System::String password = u"password";
    System::SharedPtr<System::Net::NetworkCredential> credential = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    try
    {
        System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"user@domain.com", u"user@domain.com", System::String(u"TestMailRefw - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"TestMailRefw Implement ability to create RE and FW messages from source MSG file");
        
        client->Send(message);
        
        System::SharedPtr<ExchangeMessageInfoCollection> messageInfoCol = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        if (messageInfoCol->get_Count() == 1)
        {
            System::Console::WriteLine(u"1 message in Inbox");
        }
        else
        {
            System::Console::WriteLine(u"Error! No message in Inbox");
        }
        
        System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"user@domain.com", u"user@domain.com", System::String(u"TestMailRefw - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"TestMailRefw Implement ability to create RE and FW messages from source MSG file");
        
        client->Send(message1);
        messageInfoCol = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        
        if (messageInfoCol->get_Count() == 2)
        {
            System::Console::WriteLine(u"2 messages in Inbox");
        }
        else
        {
            System::Console::WriteLine(u"Error! No new message in Inbox");
        }
        
        System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"user@domain.com", u"user@domain.com", System::String(u"TestMailRefw - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"TestMailRefw Implement ability to create RE and FW messages from source MSG file");
        message2->get_Attachments()->Add(Attachment::CreateAttachmentFromString(u"Test attachment 1", u"Attachment Name 1"));
        message2->get_Attachments()->Add(Attachment::CreateAttachmentFromString(u"Test attachment 2", u"Attachment Name 2"));
        
        // Reply, Replay All and forward Message
        client->Reply(message2, messageInfoCol->idx_get(0));
        client->ReplyAll(message2, messageInfoCol->idx_get(0));
        client->Forward(message2, messageInfoCol->idx_get(0));
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(System::String(u"Error in program") + ex->get_Message());
    }
    
}
