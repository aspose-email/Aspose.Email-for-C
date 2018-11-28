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
#include <system/array.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void GetServerExtensionsUsingPop3Client()
{
    // ExStart:GetServerExtensionsUsingPop3Client
    // Connect and log in to POP3
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(u"pop.gmail.com", u"username", u"password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    client->set_Port(993);
    System::ArrayPtr<System::String> getCaps = client->GetCapabilities();
    
    {
        for (int i_ = 0; i_ < getCaps->Count(); ++i_)
        {
            System::String item = getCaps[i_];
            {
                System::Console::WriteLine(item);
            }
        }
    }
    // ExEnd:GetServerExtensionsUsingPop3Client
}

