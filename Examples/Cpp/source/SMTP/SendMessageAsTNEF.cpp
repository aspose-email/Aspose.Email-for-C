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
#include <system/date_time.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlLoadOptions.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>
#include <Clients/SecurityOptions.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void SendMessageAsTNEF()
{
    try
    {
        // ExStart:SendMessageAsTNEF
        System::String emlFileName = GetDataDir_Email() + u"Message.eml";
        // A TNEF Email
        
        // Load from eml
        System::SharedPtr<MailMessage> eml1 = MailMessage::Load(emlFileName, System::MakeObject<EmlLoadOptions>());
        eml1->set_From(u"somename@gmail.com");
        eml1->get_To()->Clear();
        eml1->get_To()->Add(System::MakeObject<MailAddress>(u"first.last@test.com"));
        eml1->set_Subject(u"With PreserveTnef flag during loading");
        eml1->set_Date(System::DateTime::get_Now());
        System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"somename", u"password");
        client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
        client->set_UseTnef(true);
        // Use this flag to send as TNEF
        client->Send(eml1);
        // ExEnd:SendMessageAsTNEF
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
    }
    
}

