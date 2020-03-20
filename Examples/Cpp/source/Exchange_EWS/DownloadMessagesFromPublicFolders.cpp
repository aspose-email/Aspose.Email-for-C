#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <net/network_credential.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>

#include "Examples.h"


using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;


static String dataDir = GetDataDir_Exchange();
String username;
String password;
String domain;
String mailboxUri;

void ListMessagesFromSubFolder(System::SharedPtr<Aspose::Email::Clients::Exchange::ExchangeFolderInfo> publicFolder, System::SharedPtr<Aspose::Email::Clients::Exchange::WebService::IEWSClient> client)
{
    System::Console::WriteLine(System::String(u"Folder Name: ") + publicFolder->get_DisplayName());
    System::SharedPtr<ExchangeMessageInfoCollection> msgInfoCollection = client->ListMessagesFromPublicFolder(publicFolder);
    for (auto messageInfo : System::IterateOver(msgInfoCollection))
    {
        System::SharedPtr<MailMessage> msg = client->FetchMessage(messageInfo->get_UniqueUri());
        System::Console::WriteLine(msg->get_Subject());
        msg->Save(dataDir + msg->get_Subject() + u".msg", SaveOptions::get_DefaultMsgUnicode());
    }

    // Call this method recursively for any subfolders
    if (publicFolder->get_ChildFolderCount() > 0)
    {
        System::SharedPtr<ExchangeFolderInfoCollection> subfolders = client->ListSubFolders(publicFolder);
        for (System::SharedPtr<Aspose::Email::Clients::Exchange::ExchangeFolderInfo> subfolder : System::IterateOver(subfolders))
        {
            ListMessagesFromSubFolder(subfolder, client);
        }
    }
}

void ReadPublicFolders()
{
    System::SharedPtr<System::Net::NetworkCredential> credential = System::MakeObject<System::Net::NetworkCredential>(username, password, domain);
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    System::SharedPtr<ExchangeFolderInfoCollection> folders = client->ListPublicFolders();
    for (auto publicFolder : System::IterateOver(folders))
    {
        System::Console::WriteLine(System::String(u"Name: ") + publicFolder->get_DisplayName());
        System::Console::WriteLine(System::String(u"Subfolders count: ") + publicFolder->get_ChildFolderCount());
        ListMessagesFromSubFolder(publicFolder, client);

    }
}


void DownloadMessagesFromPublicFolders()
{
    try
    {
        ReadPublicFolders();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}

