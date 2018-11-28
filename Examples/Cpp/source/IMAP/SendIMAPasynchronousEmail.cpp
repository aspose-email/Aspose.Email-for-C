/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/threading/thread_pool.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/idisposable.h>
#include <system/iasyncresult.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <MailMessage.h>
#include <functional>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>
#include <Clients/IConnectionAdapter.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void SendIMAPasynchronousEmail()
{
    try
    {
        
        // ExStart:SendIMAPasynchronousEmail
        // Create an imapclient with host, user and password
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
        client->set_Host(u"domain.com");
        client->set_Username(u"username");
        client->set_Password(u"password");
        client->SelectFolder(u"InBox");
        
        System::SharedPtr<ImapMessageInfoCollection> messages = client->ListMessages();
        System::SharedPtr<System::IAsyncResult> res1 = client->BeginFetchMessage(messages->idx_get(0)->get_UniqueId());
        System::SharedPtr<System::IAsyncResult> res2 = client->BeginFetchMessage(messages->idx_get(1)->get_UniqueId());
        System::SharedPtr<MailMessage> msg1 = client->EndFetchMessage(res1);
        System::SharedPtr<MailMessage> msg2 = client->EndFetchMessage(res2);
        
        // ExEnd:SendIMAPasynchronousEmail
        
        // ExStart:SendIMAPasynchronousEmailThreadPool
        System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<MailMessage>>> List = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<MailMessage>>>();
        
        // CSPORTCPP: [WARNING] Using local variables. Make sure that local function ptr does not leave the current scope.
        std::function<void(System::SharedPtr<System::Object> o)> _local_func_0 = [&client, &List](System::SharedPtr<System::Object> o)
        {
            client->SelectFolder(u"folderName");
            System::SharedPtr<ImapMessageInfoCollection> messageInfoCol = client->ListMessages();
            
            {
                auto messageInfo_enumerator = (messageInfoCol)->GetEnumerator();
                decltype(messageInfo_enumerator->get_Current()) messageInfo;
                while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
                {
                    List->Add(client->FetchMessage(messageInfo->get_UniqueId()));
                }
            }
        };
        
        System::Threading::ThreadPool::QueueUserWorkItem(_local_func_0);
        // ExEnd:SendIMAPasynchronousEmailThreadPool
        
        // ExStart:SendIMAPasynchronousEmailThreadPool1
        System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<MailMessage>>> List1 = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<MailMessage>>>();
        
        // CSPORTCPP: [WARNING] Using local variables. Make sure that local function ptr does not leave the current scope.
        std::function<void(System::SharedPtr<System::Object> o)> _local_func_1 = [&client, &List1](System::SharedPtr<System::Object> o)
        {
            {
                System::SharedPtr<System::IDisposable> connection = client->CreateConnection();
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard<1> __dispose_guard_0({ connection});
                // ------------------------------------------
                
                try
                {
                    client->SelectFolder(u"FolderName");
                    System::SharedPtr<ImapMessageInfoCollection> messageInfoCol = client->ListMessages();
                    
                    {
                        auto messageInfo_enumerator = (messageInfoCol)->GetEnumerator();
                        decltype(messageInfo_enumerator->get_Current()) messageInfo;
                        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
                        {
                            List1->Add(client->FetchMessage(messageInfo->get_UniqueId()));
                        }
                    }
                }
                catch(...)
                {
                    __dispose_guard_0.SetCurrentException(std::current_exception());
                }
            }
        };
        
        System::Threading::ThreadPool::QueueUserWorkItem(_local_func_1);
        // ExEnd:SendIMAPasynchronousEmailThreadPool1
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
        throw;
    }
    
}

