/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Exception.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Pop3;

void GetEmailCountIntheMailbox()
{
    // ExStart:GetEmailCountIntheMailbox
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(u"pop3.server.com", u"username", u"password");
    try
    {
        client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
        int32_t i = client->GetMessageCount();
        System::Console::WriteLine(System::String(u"Message count: ") + i);
    }
    catch (Pop3Exception& ex)
    {
        System::Console::WriteLine(System::String(u"Error:") + System::ObjectExt::ToString(ex));
    }
    
    // ExEnd:GetEmailCountIntheMailbox
}

