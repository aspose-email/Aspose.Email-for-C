#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <MailMessage.h>
#include <EmlSaveOptions.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void ParseMessageAndSave()
{
    // ExStart:ParseMessageAndSave
    // The path to the File directory.
    System::String dataDir = GetDataDir_POP3();
    
    // Create an instance of the Pop3Client class
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    
    // Specify host, username and password, Port and SecurityOptions for your client
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
            // Fetch the message by its sequence number and Save the message using its subject as the file name
            System::SharedPtr<MailMessage> msg = client->FetchMessage(1);
            msg->Save(dataDir + u"first-message_out.eml", SaveOptions::get_DefaultEml());
            client->Dispose();
        }
        catch (System::Exception& ex)
        {
            System::Console::WriteLine(System::Environment::get_NewLine() + ex->get_Message());
        }
    }
    // ExEnd:ParseMessageAndSave
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Downloaded email using POP3. Message saved at " + dataDir + u"first-message_out.eml");
}

