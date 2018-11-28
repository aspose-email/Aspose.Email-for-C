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
#include <system/console.h>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;

void ListingMessagesRecursively()
{
    // ExStart:ListingMessagesRecursively
    // Create an imapclient with host, user and password
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    client->set_Host(u"domain.com");
    client->set_Username(u"username");
    client->set_Password(u"password");
    client->SelectFolder(u"InBox");
    System::SharedPtr<ImapMessageInfoCollection> msgsColl = client->ListMessages(true);
    System::Console::WriteLine(System::String(u"Total Messages: ") + msgsColl->get_Count());
    // ExEnd:ListingMessagesRecursively
}

