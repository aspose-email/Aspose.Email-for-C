/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/threading/auto_reset_event.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/iasyncresult.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/async_callback.h>
#include <MailMessage.h>
#include <functional>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3MessageInfoCollection.h>
#include <Clients/Pop3/Pop3MessageInfo.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void RetrieveMessagesAsynchronously()
{
    // ExStart:RetrieveMessagesAsynchronously
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    client->set_Host(u"pop.gmail.com");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLImplicit);
    client->set_Username(u"username");
    client->set_Password(u"password");
    
    try
    {
        System::SharedPtr<Pop3MessageInfoCollection> messages = client->ListMessages();
        System::Console::WriteLine(System::String(u"Total Number of Messages in inbox:") + messages->get_Count());
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
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    // ExEnd:RetrieveMessagesAsynchronously
}

