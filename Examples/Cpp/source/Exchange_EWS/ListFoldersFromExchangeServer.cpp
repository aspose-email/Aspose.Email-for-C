#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void ListSubFolders(System::SharedPtr<Aspose::Email::Clients::Exchange::WebService::IEWSClient> client, System::SharedPtr<Aspose::Email::Clients::Exchange::ExchangeFolderInfo> folderInfo)
{
    // Create the folder in disk (same name as on IMAP server)
    System::Console::WriteLine(folderInfo->get_DisplayName());
    try
    {
        // If this folder has sub-folders, call this method recursively to get messages
        System::SharedPtr<ExchangeFolderInfoCollection> folderInfoCollection = client->ListSubFolders(folderInfo->get_Uri());
        for (auto subfolderInfo : System::IterateOver(folderInfoCollection))
        {
            ListSubFolders(client, subfolderInfo);
        }
    }
    catch (System::Exception& ) { }

}

void ListFoldersFromExchangeServer()
{
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::Console::WriteLine(u"Downloading all messages from Inbox....");
        
        System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo();
        System::Console::WriteLine(System::String(u"Mailbox URI: ") + mailboxInfo->get_MailboxUri());
        System::String rootUri = client->GetMailboxInfo()->get_RootUri();
        // List all the folders from Exchange server
        System::SharedPtr<ExchangeFolderInfoCollection> folderInfoCollection = client->ListSubFolders(rootUri);
        for (auto folderInfo : System::IterateOver(folderInfoCollection))
        {
            // Call the recursive method to read messages and get sub-folders
            ListSubFolders(client, folderInfo);
        }
        
        System::Console::WriteLine(u"All messages downloaded.");
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}

