#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void DeletingFolders()
{
    //ExStart:DeletingFolders
    // Create an instance of the ImapClient class
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    
    // Specify host, username and password, and set port for your client
    client->set_Host(u"imap.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(993);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    try
    {
        // Rename a folder and Disconnect to the remote IMAP server
        client->DeleteFolder(u"Client");
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    //ExEnd:DeletingFolders
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Deleted folders on IMAP server.");
}

