#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <Clients/Graph/IGraphClient.h>
#include <Clients/Graph/GraphClient.h>
#include <Clients/Graph/FolderInfoCollection.h>
#include <Clients/Graph/FolderInfo.h>
#include <Clients/Base/OAuth/ITokenProvider.h>


using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Graph;

void ListFoldersExchangeGraph()
{
    try
    {
        System::SharedPtr<ITokenProvider> tokenProvider;
        System::String tenantId = u"";
        
        System::SharedPtr<IGraphClient> client = GraphClient::GetClient(tokenProvider, tenantId);
        System::Console::WriteLine(u"List all folders....");
        
        
        System::SharedPtr<FolderInfoCollection> folders = client->ListFolders();
        for (auto folderInfo : System::IterateOver(folders))
        {
            System::Console::WriteLine(folderInfo->get_DisplayName());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
