#include "Examples.h"
#include <system/console.h>
#include <system/enumerator_adapter.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <Clients/Exchange/ExchangeFolderPageInfo.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void PagingSupportForListingFolders()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    // Clearing resources under 'using' statement

    int32_t itemsPerPage = 5;
    System::SharedPtr<ExchangeFolderInfoCollection> totalFoldersCollection = client->ListSubFolders(client->get_MailboxInfo()->get_RootUri());
    System::Console::WriteLine(totalFoldersCollection->get_Count());

    /// ///////////////// RETREIVING INFORMATION USING PAGING SUPPORT //////////////////////////////////

    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<ExchangeFolderPageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<ExchangeFolderPageInfo>>>();
    System::SharedPtr<ExchangeFolderPageInfo> pagedFoldersCollection = client->ListSubFoldersByPage(client->get_MailboxInfo()->get_RootUri(), itemsPerPage);

    System::Console::WriteLine(pagedFoldersCollection->get_TotalCount());

    pages->Add(pagedFoldersCollection);
    while (!pagedFoldersCollection->get_LastPage())
    {
        pagedFoldersCollection = client->ListSubFoldersByPage(client->get_MailboxInfo()->get_RootUri(), itemsPerPage, pagedFoldersCollection->get_PageOffset() + 1);
        pages->Add(pagedFoldersCollection);
    }
    int32_t retrievedFolders = 0;
    for (auto pageCol : System::IterateOver(pages))
    {
        retrievedFolders += pageCol->get_Items()->get_Count();
    }

    // Verify the total count of folders
    System::Console::WriteLine(retrievedFolders);
}