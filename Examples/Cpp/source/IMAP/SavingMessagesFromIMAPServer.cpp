/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void SavingMessagesFromIMAPServer()
{
    // ExStart:SavingMessagesFromIMAPServer
    // The path to the file directory.
    System::String dataDir = GetDataDir_IMAP();
    
    // Create an imapclient with host, user and password
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"localhost", u"user", u"password");
    
    // Select the inbox folder and Get the message info collection
    client->SelectFolder(ImapFolderInfo::InBox);
    System::SharedPtr<ImapMessageInfoCollection> list = client->ListMessages();
    
    // Download each message
    for (int32_t i = 0; i < list->get_Count(); i++)
    {
        // Save the message in MSG format
        System::SharedPtr<MailMessage> message = client->FetchMessage(list->idx_get(i)->get_UniqueId());
        message->Save(dataDir + list->idx_get(i)->get_UniqueId() + u"_out.msg", SaveOptions::get_DefaultMsgUnicode());
    }
    // ExEnd:SavingMessagesFromIMAPServer
}

