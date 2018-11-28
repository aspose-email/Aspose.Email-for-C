#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapFolderInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void GettingFoldersInformation()
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
        // ExStart:GettingFoldersInformation
        // Get all folders in the currently subscribed folder
        System::SharedPtr<ImapFolderInfoCollection> folderInfoColl = client->ListFolders();
        
        // Iterate through the collection to get folder info one by one
        
        {
            auto folderInfo_enumerator = (folderInfoColl)->GetEnumerator();
            decltype(folderInfo_enumerator->get_Current()) folderInfo;
            while (folderInfo_enumerator->MoveNext() && (folderInfo = folderInfo_enumerator->get_Current(), true))
            {
                // Folder name and get New messages in the folder
                System::Console::WriteLine(System::String(u"Folder name is ") + folderInfo->get_Name());
                System::SharedPtr<ImapFolderInfo> folderExtInfo = client->GetFolderInfo(folderInfo->get_Name());
                System::Console::WriteLine(System::String(u"New message count: ") + folderExtInfo->get_NewMessageCount());
                System::Console::WriteLine(System::String(u"Is it readonly? ") + folderExtInfo->get_ReadOnly());
                System::Console::WriteLine(System::String(u"Total number of messages ") + folderExtInfo->get_TotalMessageCount());
            }
        }
        // ExEnd:GettingFoldersInformation
        
        // Disconnect to the remote IMAP server
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Getting folders information from IMAP server.");
}

