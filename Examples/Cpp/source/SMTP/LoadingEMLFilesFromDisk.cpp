/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <MailMessage.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email;

void LoadingEMLFilesFromDisk()
{
    System::String dataDir = GetDataDir_SMTP();
    
    // ExStart:LoadingEMLFilesFromDisk
    // Load an EML file in MailMessage class
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"test.eml");
    
    // Send this message using SmtpClient
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"host", u"username", u"password");
    
    try
    {
        client->Send(message);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
    // ExEnd:LoadingEMLFilesFromDisk
}

