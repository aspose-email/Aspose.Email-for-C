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
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;

void DeleteEmailByIndex()
{
    // ExStart:DeleteEmailByIndex
    // Create a POP3 client
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(u"mail.aspose.com", 110, u"username", u"psw");
    try
    {
        // Delete all the message one by one
        int32_t messageCount = client->GetMessageCount();
        for (int32_t i = 1; i <= messageCount; i++)
        {
            client->DeleteMessage(i);
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    // ExEnd:DeleteEmailByIndex
}

