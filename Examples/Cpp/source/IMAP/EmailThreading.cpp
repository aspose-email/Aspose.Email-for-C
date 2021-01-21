#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/list_ext.h>
#include <system/collections/list.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/XGMThreadSearchConditions.h>
#include <Clients/Imap/MessageThreadResult.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>


using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;
using namespace System;
using namespace System::Collections::Generic;

void PrintConversaton(String indent, SharedPtr<List<SharedPtr<MessageThreadResult>>> conversation, SharedPtr<List<SharedPtr<ImapMessageInfo>>> messages)
{
    for (auto thread : IterateOver(conversation))
    {
        System::String subject;
        for (auto message : IterateOver(messages))
        {
            if (message->get_UniqueId() == thread->get_UniqueId())
            {
                subject = message->get_Subject();
                break;
            }
        }
        System::Console::WriteLine(u"{0} ({1}) {2}", indent, thread->get_UniqueId(), subject);
        
        if (thread->get_ChildMessages()->get_Count() != 0)
        {
            PrintConversaton(indent += u"-", thread->get_ChildMessages(), messages);
        }
    }
}

void IMAPEmailThreading()
{
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.gmail.com", 993, u"username", u"password", Aspose::Email::Clients::SecurityOptions::SSLImplicit);

    client->SelectFolder(ImapFolderInfo::InBox);
    // get a list of messages that we'll group by conversation
    System::SharedPtr<ImapMessageInfoCollection> messages = client->ListMessages();
    // make sure the IMAP server supports X-GM-EXT-1 extension
    if (client->get_GmExt1Supported())
    {
        for (auto message : IterateOver(messages))
        {
            String conversationId = message->get_ConversationId();
            if (String::IsNullOrEmpty(conversationId))
            {
                continue;
            }
                    
            // create the necessary search conditions for a thread
            auto conditions = MakeObject<XGMThreadSearchConditions>(); 
            conditions->set_ConversationId(conversationId); 
            conditions->set_UseUId(true); 
            // get results
            System::SharedPtr<List<SharedPtr<MessageThreadResult>>> conversation = client->GetMessageThreads(conditions);
            // print the email conversation in hierarchically manner
            PrintConversaton(u"", conversation, ImapMessageInfoCollection::to_List(messages));
            System::Console::WriteLine(System::String(u'-', 20));
        }
    }
}
