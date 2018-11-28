/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/threading/auto_reset_event.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/iasyncresult.h>
#include <system/details/dispose_guard.h>
#include <system/async_callback.h>
#include <MailMessage.h>
#include <functional>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void RetrievingMessagesAsynchronously()
{
    // ExStart:RetrievingMessagesAsynchronously
    // Connect and log in to IMAP
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"host", u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ client});
        // ------------------------------------------
        
        try
        {
            client->SelectFolder(u"Issues/SubFolder");
            System::SharedPtr<ImapMessageInfoCollection> messages = client->ListMessages();
            System::SharedPtr<System::Threading::AutoResetEvent> evnt = System::MakeObject<System::Threading::AutoResetEvent>(false);
            System::SharedPtr<MailMessage> message;
            
            // CSPORTCPP: [WARNING] Using local variables. Make sure that local function ptr does not leave the current scope.
            std::function<void(System::SharedPtr<System::IAsyncResult> ar)> _local_func_0 = [&message, &client, &evnt](System::SharedPtr<System::IAsyncResult> ar)
            {
                message = client->EndFetchMessage(ar);
                evnt->Set();
            };
            
            System::AsyncCallback callback = _local_func_0;
            client->BeginFetchMessage(messages->idx_get(0)->get_SequenceNumber(), static_cast<System::AsyncCallback>(callback), nullptr);
            evnt->WaitOne();
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:RetrievingMessagesAsynchronously
}

