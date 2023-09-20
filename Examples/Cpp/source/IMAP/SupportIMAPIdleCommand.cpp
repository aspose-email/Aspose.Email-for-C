/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/threading/thread.h>
#include <system/threading/manual_reset_event.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/console.h>
#include <system/array.h>
#include <MailMessage.h>
#include <functional>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/Imap/ImapMonitoringEventArgs.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email;

void SupportIMAPIdleCommand()
{
    // ExStart:SupportIMAPIdleCommand
    // Connect and log in to IMAP 
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.domain.com", u"username", u"password");
    
    System::SharedPtr<System::Threading::ManualResetEvent> manualResetEvent = System::MakeObject<System::Threading::ManualResetEvent>(false);
    System::SharedPtr<ImapMonitoringEventArgs> eventArgs;
    
    // CSPORTCPP: [WARNING] Using local variables. Make sure that local function ptr does not leave the current scope.
    std::function<void(System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringEventArgs> e)> callback = [&eventArgs, &manualResetEvent](System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringEventArgs> e)
    {
        eventArgs = e;
        manualResetEvent->Set();
    };

    std::function<void(System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringErrorEventArgs> e)> errorCallback = [&eventArgs, &manualResetEvent](System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringErrorEventArgs> e)
    {
    };

    
    client->StartMonitoring(callback, errorCallback);
    System::Threading::Thread::Sleep(2000);
    System::SharedPtr<SmtpClient> smtpClient = System::MakeObject<SmtpClient>(u"exchange.aspose.com", u"username", u"password");
    smtpClient->Send(System::MakeObject<MailMessage>(u"from@aspose.com", u"to@aspose.com", System::String(u"EMAILNET-34875 - ") + System::Guid::NewGuid(), u"EMAILNET-34875 Support for IMAP idle command"));
    manualResetEvent->WaitOne(10000);
    manualResetEvent->Reset();
    System::Console::WriteLine(eventArgs->get_NewMessages()->get_Length());
    System::Console::WriteLine(eventArgs->get_DeletedMessages()->get_Length());
    client->StopMonitoring(u"Inbox");
    smtpClient->Send(System::MakeObject<MailMessage>(u"from@aspose.com", u"to@aspose.com", System::String(u"EMAILNET-34875 - ") + System::Guid::NewGuid(), u"EMAILNET-34875 Support for IMAP idle command"));
    manualResetEvent->WaitOne(5000);
    // ExEnd:SupportIMAPIdleCommand
}

