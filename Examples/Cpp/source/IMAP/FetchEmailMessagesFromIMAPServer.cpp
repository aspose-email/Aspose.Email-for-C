/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

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

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;

void FetchEmailMessagesFromIMAPServer()
{
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
        // ExStart:FetchEmailMessagesFromIMAPServer
        // Select the inbox folder and Get the message info collection
        client->SelectFolder(ImapFolderInfo::InBox);
        System::SharedPtr<ImapMessageInfoCollection> list = client->ListMessages();
        
        // Download each message
        for (int32_t i = 0; i < list->get_Count(); i++)
        {
            // Save the EML file locally
            client->SaveMessage(list->idx_get(i)->get_UniqueId(), dataDir + list->idx_get(i)->get_UniqueId() + u".eml");
        }
        // ExEnd:FetchEmailMessagesFromIMAPServer
        
        // Disconnect to the remote IMAP server
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
}

