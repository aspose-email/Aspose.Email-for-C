#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;

void ConnectingWithIMAPServer()
{
    // ExStart:ConnectingWithIMAPServer
    // Create an imapclient with host, user and password
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"localhost", u"user", u"password");
    // ExEnd:ConnectingWithIMAPServer
    
    try
    {
        // Disconnect to the remote IMAP server
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Connected to IMAP server.");
}

