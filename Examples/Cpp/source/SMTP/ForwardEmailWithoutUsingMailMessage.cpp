/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <MailAddressCollection.h>
#include <cstdint>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Smtp;

void ForwardEmailWithoutUsingMailMessage()
{
    //ExStart: ForwardEmailWithoutUsingMailMessage
    System::String dataDir = GetDataDir_Email();
    
    System::String host = u"mail.server.com";
    System::String username = u"username";
    System::String password = u"password";
    int32_t smtpPort = 587;
    System::String sender = u"Sender@domain.com";
    System::SharedPtr<MailAddressCollection> recipients = System::MakeObject<MailAddressCollection>();
    recipients->Add(u"recepient1@domain.com, recepient2@domain.com");
    
    {
        System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(host, smtpPort, username, password, Aspose::Email::Clients::SecurityOptions::Auto);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            System::String fileName = u"test.eml";
            {
                System::SharedPtr<System::IO::FileStream> fs = System::IO::File::OpenRead(dataDir + fileName);
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard<1> __dispose_guard_0({ fs});
                // ------------------------------------------
                
                try
                {
                    client->Forward(sender, recipients, fs);
                }
                catch(...)
                {
                    __dispose_guard_0.SetCurrentException(std::current_exception());
                }
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    //ExEnd: ForwardEmailWithoutUsingMailMessage
}

