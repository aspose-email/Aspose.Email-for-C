#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
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
#include <Clients/Imap/Search/ImapQueryBuilder.h>
#include <Clients/Imap/ImapPageInfo.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;
using namespace Aspose::Email;

void SearchWithPagingSupport()
{
    // ExStart:SearchWithPagingSupport
    /// <summary>
    /// This example shows how to search for messages using ImapClient of the API with paging support
    /// Introduced in Aspose.Email for .NET 6.4.0
    /// </summary>
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"host.domain.com", 84, u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            
            {
                auto __finally_guard_0 = ::System::MakeScopeGuard([=]() { });
                
                try
                {
                    // Append some test messages
                    int32_t messagesNum = 12;
                    int32_t itemsPerPage = 5;
                    System::SharedPtr<MailMessage> message;
                    for (int32_t i = 0; i < messagesNum; i++)
                    {
                        message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-35128 - ") + System::Guid::NewGuid(), u"111111111111111");
                        client->AppendMessage(ImapFolderInfo::InBox, message);
                    }
                    System::String body = u"2222222222222";
                    for (int32_t i = 0; i < messagesNum; i++)
                    {
                        message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-35128 - ") + System::Guid::NewGuid(), body);
                        client->AppendMessage(ImapFolderInfo::InBox, message);
                    }
                    
                    client->SelectFolder(u"Inbox");
                    System::SharedPtr<ImapQueryBuilder> iqb = System::MakeObject<ImapQueryBuilder>();
                    iqb->get_Body()->Contains(body);
                    System::SharedPtr<MailQuery> query = iqb->GetQuery();
                    
                    client->SelectFolder(ImapFolderInfo::InBox);
                    System::SharedPtr<ImapMessageInfoCollection> totalMessageInfoCol = client->ListMessages(query);
                    System::Console::WriteLine(totalMessageInfoCol->get_Count());
                    
                    /// ///////////////////////////////////////////////////
                    
                    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<ImapPageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<ImapPageInfo>>>();
                    System::SharedPtr<PageSettings> pageSettings = System::MakeObject<PageSettings>();
                    System::SharedPtr<ImapPageInfo> pageInfo = client->ListMessagesByPage(ImapFolderInfo::InBox, query, itemsPerPage);
                    pages->Add(pageInfo);
                    while (!pageInfo->get_LastPage())
                    {
                        pageInfo = client->ListMessagesByPage(ImapFolderInfo::InBox, query, pageInfo->get_NextPage());
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
    // ExEnd: SearchWithPagingSupport
}

