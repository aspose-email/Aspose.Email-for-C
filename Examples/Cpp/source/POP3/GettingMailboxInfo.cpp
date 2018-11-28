#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3MailboxInfo.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void GettingMailboxInfo()
{
    // Create an instance of the Pop3Client class
    //ExStart:GettingMailboxInfo
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    // Specify host, username, password, Port and SecurityOptions for your client
    client->set_Host(u"pop.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
    // Get the size of the mailbox,  Get mailbox info, number of messages in the mailbox
    int64_t nSize = client->GetMailboxSize();
    System::Console::WriteLine(System::String(u"Mailbox size is ") + nSize + u" bytes.");
    System::SharedPtr<Pop3MailboxInfo> info = client->GetMailboxInfo();
    int32_t nMessageCount = info->get_MessageCount();
    System::Console::WriteLine(System::String(u"Number of messages in mailbox are ") + nMessageCount);
    int64_t nOccupiedSize = info->get_OccupiedSize();
    System::Console::WriteLine(System::String(u"Occupied size is ") + nOccupiedSize);
    //ExEnd:GettingMailboxInfo
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Getting the mailbox information of POP3 server.");
}

