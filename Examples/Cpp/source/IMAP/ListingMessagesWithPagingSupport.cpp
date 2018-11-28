#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/PageInfo.h>
#include <Clients/Imap/ImapPageInfo.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/PageSettings.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void ListingMessagesWithPagingSupport()
{
    // ExStart: ListingMessagesWithPagingSupport
    /// <summary>
    /// This example shows the paging support of ImapClient for listing messages from the server
    /// Available in Aspose.Email for .NET 6.4.0 and onwards
    /// </summary>
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"host.domain.com", 993, u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            
            {
                auto __finally_guard_0 = ::System::MakeScopeGuard([=]() { });
                
                try
                {
                    int32_t messagesNum = 12;
                    int32_t itemsPerPage = 5;
                    System::SharedPtr<MailMessage> message;
                    // Create some test messages and append these to server's inbox
                    for (int32_t i = 0; i < messagesNum; i++)
                    {
                        message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-35157 - ") + System::Guid::NewGuid(), u"EMAILNET-35157 Move paging parameters to separate class");
                        client->AppendMessage(ImapFolderInfo::InBox, message);
                    }
                    
                    // List messages from inbox
                    client->SelectFolder(ImapFolderInfo::InBox);
                    System::SharedPtr<ImapMessageInfoCollection> totalMessageInfoCol = client->ListMessages();
                    // Verify the number of messages added
                    System::Console::WriteLine(totalMessageInfoCol->get_Count());
                    
                    /// /////////////// RETREIVE THE MESSAGES USING PAGING SUPPORT////////////////////////////////////
                    
                    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<ImapPageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<ImapPageInfo>>>();
                    System::SharedPtr<PageSettings> pageSettings = System::MakeObject<PageSettings>();
                    System::SharedPtr<ImapPageInfo> pageInfo = client->ListMessagesByPage(itemsPerPage, 0, pageSettings);
                    System::Console::WriteLine(pageInfo->get_TotalCount());
                    pages->Add(pageInfo);
                    while (!pageInfo->get_LastPage())
                    {
                        pageInfo = client->ListMessagesByPage(itemsPerPage, pageInfo->get_NextPage()->get_PageOffset(), pageSettings);
                        pages->Add(pageInfo);
                    }
                    int32_t retrievedItems = 0;
                    
                    {
                        auto folderCol_enumerator = (pages)->GetEnumerator();
                        decltype(folderCol_enumerator->get_Current()) folderCol;
                        while (folderCol_enumerator->MoveNext() && (folderCol = folderCol_enumerator->get_Current(), true))
                        {
                            retrievedItems += folderCol->get_Items()->get_Count();
                        }
                    }
                    System::Console::WriteLine(retrievedItems);
                }
                catch (...)
                {
                    throw;
                }
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd: ListingMessagesWithPagingSupport
}

