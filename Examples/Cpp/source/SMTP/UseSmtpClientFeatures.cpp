/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/shared_ptr.h>
#include <system/object.h>
#include <cstdint>
#include <Clients/Smtp/SmtpDeliveryMethod.h>
#include <Clients/Smtp/SmtpClient/SmtpClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Smtp;

void UseSmtpClientFeatures()
{
    // ExStart:SetAuthenticationMethod
    // Create an instance of SmtpClient class
    System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.domain.com", 25);
    // ExEnd:SetAuthenticationMethod
    
    // ExStart:SetDeliveryMethod
    client->set_DeliveryMethod(Aspose::Email::Clients::Smtp::SmtpDeliveryMethod::Network);
    // ExEnd:SetDeliveryMethod
    
    // ExStart:SetTimeout
    client->set_Timeout(10000);
    // ExEnd:SetTimeout
}

