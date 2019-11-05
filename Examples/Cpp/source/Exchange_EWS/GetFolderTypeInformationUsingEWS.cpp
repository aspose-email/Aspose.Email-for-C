#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <net/network_credential.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>
#include <Clients/Exchange/ExchangeFolderType.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>


using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
void GetFolderTypeInformationUsingEWS()
{
    const System::String mailboxUri = u"https://exchange/ews/exchange.asmx";
    const System::String domain = u"";
    const System::String username = u"username@ASE305.onmicrosoft.com";
    const System::String password = u"password";
    System::SharedPtr<System::Net::NetworkCredential> credentials = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::SharedPtr<ExchangeFolderInfoCollection> folderInfoCol = client->ListSubFolders(client->get_MailboxInfo()->get_RootUri());
    for (auto folderInfo : System::IterateOver(folderInfoCol))
    {
        switch (folderInfo->get_FolderType())
        {
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::Appointment:
                break;
            
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::Contact:
                break;
            
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::Task:
                break;
            
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::Note:
                break;
            
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::StickyNote:
                break;
            
            case Aspose::Email::Clients::Exchange::ExchangeFolderType::Journal:
                break;
            
            default: 
                break;
            
        }
    }
}
