#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapMessageFlags.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void RemovingMessageFlags()
{
    // Create an instance of the ImapClient class
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    
    // Specify host, username, password, Port and SecurityOptions for your client
    client->set_Host(u"imap.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(993);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    try
    {
        System::Console::WriteLine(u"Logged in to the IMAP server");
        
        // ExStart:RemovingMessageFlags
        // Remove the message flag
        client->RemoveMessageFlags(1, ImapMessageFlags::get_IsRead());
        // ExEnd:RemovingMessageFlags
        
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Removed message flags from IMAP server.");
}

