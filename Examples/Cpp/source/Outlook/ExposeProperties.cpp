/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/EmlLoadOptions.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ExposeProperties()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // Load mail message
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + L"Message.eml", System::MakeObject<EmlLoadOptions>());
    
    // Subject
    if (msg->get_Subject() != nullptr)
    {
        System::Console::WriteLine(msg->get_Subject());
    }
    else
    {
        System::Console::WriteLine(L"no subject");
    }
    
    // From
    if (msg->get_From() != nullptr)
    {
        System::Console::WriteLine(msg->get_From());
    }
    else
    {
        System::Console::WriteLine(L"No sender");
    }
    
    // To
    if (msg->get_To() != nullptr)
    {
        System::Console::WriteLine(msg->get_To());
    }
    else
    {
        System::Console::WriteLine(L"No one in To");
    }
    
    // Cc
    if (msg->get_CC() != nullptr)
    {
        System::Console::WriteLine(msg->get_CC());
    }
    else
    {
        System::Console::WriteLine(L"No one in cc");
    }
}







