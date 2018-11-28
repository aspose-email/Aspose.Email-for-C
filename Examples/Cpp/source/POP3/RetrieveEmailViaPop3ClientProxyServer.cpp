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
#include <system/exceptions.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Proxy/SocksVersions.h>
#include <Clients/Proxy/SocksProxy.h>
#include <Clients/Proxy/Proxy.h>
#include <Clients/Pop3/Pop3MailboxInfo.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void RetrieveEmailViaPop3ClientProxyServer()
{
    // ExStart:RetrieveEmailViaPop3ClientProxyServer
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(u"pop.domain.com", u"username", u"password");
    
    // Set proxy address, Port and Proxy
    System::String proxyAddress = u"192.168.203.142";
    int32_t proxyPort = 1080;
    System::SharedPtr<SocksProxy> proxy = System::MakeObject<SocksProxy>(proxyAddress, proxyPort, Aspose::Email::Clients::SocksVersion::SocksV5);
    client->set_Proxy(proxy);
    
    try
    {
        System::SharedPtr<Pop3MailboxInfo> mailboxInfo = client->GetMailboxInfo();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
    // ExEnd:RetrieveEmailViaPop3ClientProxyServer
}

