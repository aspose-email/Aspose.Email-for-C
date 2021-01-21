#include <system/string.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void ValidateIMAPServerCredentials()
{
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.domain.com", 993, u"user@domain.com", u"pwd");
    client->set_Timeout(4000);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);

    if (client->ValidateCredentials())
    {
        System::Console::WriteLine(u"Credentials validated");
    }
    else
    {
        System::Console::WriteLine(u"Wrong Credentials");
    }
}
