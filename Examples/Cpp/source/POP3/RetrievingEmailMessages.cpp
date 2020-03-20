#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void RetrievingEmailMessages()
{
    //ExStart:RetrievingEmailMessages
    // Create an instance of the Pop3Client class
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    
    // Specify host, username, password, Port and SecurityOptions for your client
    client->set_Host(u"pop.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
    {
        auto __finally_guard_0 = ::System::MakeScopeGuard([=]()
        {
            client->Dispose();
        });
        
        try
        {
            int32_t messageCount = client->GetMessageCount();
            // Create an instance of the MailMessage class and Retrieve message
            System::SharedPtr<MailMessage> message;
            for (int32_t i = 1; i <= messageCount; i++)
            {
                message = client->FetchMessage(i);
                System::Console::WriteLine(System::String(u"From:") + message->get_From());
                System::Console::WriteLine(System::String(u"Subject:") + message->get_Subject());
                System::Console::WriteLine(message->get_HtmlBody());
            }
        }
        catch (System::Exception& ex)
        {
            System::Console::WriteLine(ex->get_Message());
        }
    }
    //ExEnd:RetrievingEmailMessages
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Retrieved email messages using POP3 ");
}

