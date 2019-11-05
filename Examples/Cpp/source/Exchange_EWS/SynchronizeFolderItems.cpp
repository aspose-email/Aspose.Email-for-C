#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/dictionary.h>
#include <system/array.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/SyncFolderResult.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void SynchronizeFolderItems()
{
    try
    {
        
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"user@domain.com", u"user@domain.com", System::String(u"EMAILNET-34738 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-34738 Sync Folder Items");
        client->Send(message1);
        
        System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"user@domain.com", u"user@domain.com", System::String(u"EMAILNET-34738 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-34738 Sync Folder Items");
        client->Send(message2);
        
        System::SharedPtr<ExchangeMessageInfoCollection> messageInfoCol = client->ListMessages(client->get_MailboxInfo()->get_InboxUri());
        System::SharedPtr<SyncFolderResult> result = client->SyncFolder(client->get_MailboxInfo()->get_InboxUri(), nullptr);
        System::Console::WriteLine(result->get_NewItems()->get_Count());
        System::Console::WriteLine(result->get_ChangedItems()->get_Count());
        System::Console::WriteLine(result->get_ReadFlagChanged()->get_Count());
        System::Console::WriteLine(result->get_DeletedItems()->get_Length());
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex.get_Message());
    }
    
}
