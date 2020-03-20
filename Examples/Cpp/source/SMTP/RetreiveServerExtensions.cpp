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
#include <system/array.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Smtp;

void RetreiveServerExtensions()
{
    // ExStart:RetreiveSMTPServerExtensions
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", u"user@gmail.com", u"password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);
    client->set_Port(587);
    
    try
    {
        System::ArrayPtr<System::String> caps = client->GetCapabilities();
        
        
        {
            for (int i_ = 0; i_ < caps->Count(); ++i_)
            {
                System::String str = caps[i_];
                {
                    System::Console::WriteLine(str);
                }
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    // ExEnd:RetreiveSMTPServerExtensions
}

