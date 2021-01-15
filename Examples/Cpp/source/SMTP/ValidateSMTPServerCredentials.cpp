#include "ValidateSMTPServerCredentials.h"

#include <system/string.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>


using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
namespace Aspose {

namespace Email {

namespace Examples {

namespace CSharp {

namespace Email {

namespace SMTP {

RTTI_INFO_IMPL_HASH(3340823844u, ::Aspose::Email::Examples::CSharp::Email::SMTP::ValidateSMTPServerCredentials, ThisTypeBaseTypesInfo);

void ValidateSMTPServerCredentials::Run()
{
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com");
    
    // Set username, Password, Port No, and SecurityOptions
    client->set_Username(u"your.email@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(587);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
    
    client->set_Timeout(4000);
    
    if (client->ValidateCredentials())
    {
        System::Console::WriteLine(u"Credentials validated");
    }
    else
    {
        System::Console::WriteLine(u"Wrong Credentials");
    }
    
}

} // namespace SMTP
} // namespace Email
} // namespace CSharp
} // namespace Examples
} // namespace Email
} // namespace Aspose
