#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapFolderInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void ListMessagesInFolder(System::SharedPtr<Aspose::Email::Clients::Imap::ImapFolderInfo> folderInfo, System::String rootFolder, System::SharedPtr<Aspose::Email::Clients::Imap::ImapClient> client)
{
    // Create the folder in disk (same name as on IMAP server)
    System::String currentFolder = GetDataDir_IMAP();
    System::IO::Directory::CreateDirectory_(currentFolder);
    
    // Read the messages from the current folder, if it is selectable
    if (folderInfo->get_Selectable())
    {
        // Send status command to get folder info
        System::SharedPtr<ImapFolderInfo> folderInfoStatus = client->GetFolderInfo(folderInfo->get_Name());
        System::Console::WriteLine(folderInfoStatus->get_Name() + u" folder selected. New messages: " + folderInfoStatus->get_NewMessageCount() + u", Total messages: " + folderInfoStatus->get_TotalMessageCount());
        
        // Select the current folder and List messages
        client->SelectFolder(folderInfo->get_Name());
        System::SharedPtr<ImapMessageInfoCollection> msgInfoColl = client->ListMessages();
        System::Console::WriteLine(u"Listing messages....");
        
        {
            auto msgInfo_enumerator = (msgInfoColl)->GetEnumerator();
            decltype(msgInfo_enumerator->get_Current()) msgInfo;
            while (msgInfo_enumerator->MoveNext() && (msgInfo = msgInfo_enumerator->get_Current(), true))
            {
                // Get subject and other properties of the message
                System::Console::WriteLine(System::String(u"Subject: ") + msgInfo->get_Subject());
                System::Console::WriteLine(System::String(u"Read: ") + msgInfo->get_IsRead() + u", Recent: " + msgInfo->get_Recent() + u", Answered: " + msgInfo->get_Answered());
                
                // Get rid of characters like ? and :, which should not be included in a file name and Save the message in MSG format
                System::String fileName = msgInfo->get_Subject().Replace(u":", u" ").Replace(u"?", u" ");
                System::SharedPtr<MailMessage> msg = client->FetchMessage(msgInfo->get_SequenceNumber());
                msg->Save(currentFolder + u"\\" + fileName + u"-" + msgInfo->get_SequenceNumber() + u".msg", SaveOptions::get_DefaultMsgUnicode());
            }
        }
        System::Console::WriteLine(u"============================\n");
    }
    else
    {
        System::Console::WriteLine(folderInfo->get_Name() + u" is not selectable.");
    }
    
    try
    {
        // If this folder has sub-folders, call this method recursively to get messages
        System::SharedPtr<ImapFolderInfoCollection> folderInfoCollection = client->ListFolders(folderInfo->get_Name());
        
        {
            auto subfolderInfo_enumerator = (folderInfoCollection)->GetEnumerator();
            decltype(subfolderInfo_enumerator->get_Current()) subfolderInfo;
            while (subfolderInfo_enumerator->MoveNext() && (subfolderInfo = subfolderInfo_enumerator->get_Current(), true))
            {
                ListMessagesInFolder(subfolderInfo, rootFolder, client);
            }
        }
    }
    catch (System::Exception& ) { }
    
}


void ReadMessagesRecursively()
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
        // The root folder (which will be created on disk) consists of host and username
        System::String rootFolder = client->get_Host() + u"-" + client->get_Username();
        
        // Create the root folder and List all the folders from IMAP server
        System::IO::Directory::CreateDirectory_(rootFolder);
        System::SharedPtr<ImapFolderInfoCollection> folderInfoCollection = client->ListFolders();
        
        {
            auto folderInfo_enumerator = (folderInfoCollection)->GetEnumerator();
            decltype(folderInfo_enumerator->get_Current()) folderInfo;
            while (folderInfo_enumerator->MoveNext() && (folderInfo = folderInfo_enumerator->get_Current(), true))
            {
                // Call the recursive method to read messages and get sub-folders
                ListMessagesInFolder(folderInfo, rootFolder, client);
            }
        }
        // Disconnect to the remote IMAP server
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Downloaded messages recursively from IMAP server.");
}


