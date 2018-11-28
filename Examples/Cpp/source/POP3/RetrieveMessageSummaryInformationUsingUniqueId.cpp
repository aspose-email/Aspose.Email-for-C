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
#include <system/date_time.h>
#include <system/console.h>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3MessageInfo.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void RetrieveMessageSummaryInformationUsingUniqueId()
{
    // ExStart:RetrieveMessageSummaryInformationUsingUniqueId
    System::String uniqueId = u"unique id of a message from server";
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(u"host.domain.com", 456, u"username", u"password");
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    System::SharedPtr<Pop3MessageInfo> messageInfo = client->GetMessageInfo(uniqueId);
    
    if (messageInfo != nullptr)
    {
        System::Console::WriteLine(messageInfo->get_Subject());
        System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(messageInfo->get_Date()));
    }
    // ExEnd:RetrieveMessageSummaryInformationUsingUniqueId
}

