#include "ValidatePOP3ServerCredentials.h"

#include <system/string.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>


using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;
namespace Aspose {

namespace Email {

namespace Examples {

namespace CSharp {

namespace Email {

namespace POP3 {

RTTI_INFO_IMPL_HASH(3725125068u, ::Aspose::Email::Examples::CSharp::Email::POP3::ValidatePOP3ServerCredentials, ThisTypeBaseTypesInfo);

void ValidatePOP3ServerCredentials::Run()
{
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    
    client->set_Host(u"pop.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
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

} // namespace POP3
} // namespace Email
} // namespace CSharp
} // namespace Examples
} // namespace Email
} // namespace Aspose
