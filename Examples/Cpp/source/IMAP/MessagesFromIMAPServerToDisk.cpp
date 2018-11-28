#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void MessagesFromIMAPServerToDisk()
{
    // ExStart:MessagesFromIMAPServerToDisk
    // The path to the File directory.
    System::String dataDir = GetDataDir_IMAP();
    
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
        // Select the inbox folder and Get the message info collection
        client->SelectFolder(ImapFolderInfo::InBox);
        System::SharedPtr<ImapMessageInfoCollection> list = client->ListMessages();
        
        // Download each message
        for (int32_t i = 0; i < list->get_Count(); i++)
        {
            // Save the EML file locally
            client->SaveMessage(list->idx_get(i)->get_UniqueId(), dataDir + list->idx_get(i)->get_UniqueId() + u".eml");
        }
        // Disconnect to the remote IMAP server
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    // ExStart:MessagesFromIMAPServerToDisk
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Downloaded messages from IMAP server.");
}

