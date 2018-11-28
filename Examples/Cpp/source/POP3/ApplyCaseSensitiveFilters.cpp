/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQueryBuilder.h>
#include <Tools/Search/MailQuery.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Pop3/Pop3MessageInfoCollection.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Tools::Search;

void ApplyCaseSensitiveFilters()
{
    
    // Connect and log in to POP3
    const System::String host = u"host";
    const int32_t port = 110;
    const System::String username = u"user@host.com";
    const System::String password = u"password";
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(host, port, username, password);
    
    try
    {
        // ExStart:ApplyCaseSensitiveFilters
        // IgnoreCase is True
        System::SharedPtr<MailQueryBuilder> builder1 = System::MakeObject<MailQueryBuilder>();
        builder1->get_From()->Contains(u"tesT", true);
        System::SharedPtr<MailQuery> query1 = builder1->GetQuery();
        System::SharedPtr<Pop3MessageInfoCollection> messageInfoCol1 = client->ListMessages(query1);
        // ExEnd:ApplyCaseSensitiveFilters
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}

