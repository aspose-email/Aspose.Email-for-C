#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void CreateFoldersOnExchangeServerMailbox()
{
    
    // Create instance of EWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::String inbox = client->get_MailboxInfo()->get_InboxUri();
    System::String folderName1 = u"EMAILNET-35054";
    System::String subFolderName0 = u"2015";
    System::String folderName2 = folderName1 + u"/" + subFolderName0;
    System::String folderName3 = folderName1 + u" / 2015";
    System::SharedPtr<ExchangeFolderInfo> rootFolderInfo;
    System::SharedPtr<ExchangeFolderInfo> folderInfo;
    
    //            try
    
    {
        client->set_UseSlashAsFolderSeparator(true);
        client->CreateFolder(client->get_MailboxInfo()->get_InboxUri(), folderName1);
        client->CreateFolder(client->get_MailboxInfo()->get_InboxUri(), folderName2);
    }
    //            finally
    
    {
        if (client->FolderExists(inbox, folderName1, rootFolderInfo))
        {
            if (client->FolderExists(inbox, folderName2, folderInfo))
            {
                client->DeleteFolder(folderInfo->get_Uri(), true);
            }
            client->DeleteFolder(rootFolderInfo->get_Uri(), true);
        }
    }
}
