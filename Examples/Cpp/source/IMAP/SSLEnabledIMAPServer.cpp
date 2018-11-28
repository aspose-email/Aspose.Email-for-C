#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void SSLEnabledIMAPServer()
{
    //ExStart:SSLEnabledIMAPServer
    // Create an instance of the ImapClient class
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.domain.com", 993, u"user@domain.com", u"pwd");
    
    // Set the security mode to implicit
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLImplicit);
    //ExEnd:SSLEnabledIMAPServer
    
    try
    {
        System::Console::WriteLine(u"Logged in to the IMAP server");
        // Disconnect to the remote IMAP server
        client->Dispose();
        System::Console::WriteLine(u"Disconnected from the IMAP server");
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Connected to IMAP server with SSL.");
}

