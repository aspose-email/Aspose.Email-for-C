#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <Storage/Pst/BackupOptions.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Storage::Pst;
using namespace Aspose::Email::Clients::Exchange;
void ExchangeFoldersBackupToPST()
{
    System::String dataDir = GetDataDir_Exchange();
    // Create instance of IEWSClient class by providing credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    // Get Exchange mailbox info of other email account
    System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo();
    System::SharedPtr<ExchangeFolderInfo> info = client->GetFolderInfo(mailboxInfo->get_InboxUri());
    System::SharedPtr<ExchangeFolderInfoCollection> fc = System::MakeObject<ExchangeFolderInfoCollection>();
    fc->Add(info);
    try 
    {
        client->Backup(fc, dataDir + u"Backup_out.pst", Aspose::Email::Storage::Pst::BackupOptions::None);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}
