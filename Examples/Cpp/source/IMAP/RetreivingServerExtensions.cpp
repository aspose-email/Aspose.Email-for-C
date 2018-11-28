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
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;

void RetreivingServerExtensions()
{
    // ExStart:RetreivingServerExtensions
    // Connect and log in to IMAP
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.gmail.com", u"username", u"password");
    System::ArrayPtr<System::String> getCapabilities = client->GetCapabilities();
    
    {
        for (int i_ = 0; i_ < getCapabilities->Count(); ++i_)
        {
            System::String getCap = getCapabilities[i_];
            {
                System::Console::WriteLine(getCap);
            }
        }
    }
    // ExEnd:RetreivingServerExtensions
}

