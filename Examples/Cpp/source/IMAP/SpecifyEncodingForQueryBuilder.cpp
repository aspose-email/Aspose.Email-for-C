/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <cstdint>
#include <Clients/Imap/Search/ImapQueryBuilder.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;

void SpecifyEncodingForQueryBuilder()
{
    // Connect and log in to IMAP
    const System::String host = u"host";
    const int32_t port = 143;
    const System::String username = u"user@host.com";
    const System::String password = u"password";
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(host, port, username, password);
    
    try
    {
        client->SelectFolder(u"Inbox");
        
        // ExStart:SpecifyEncodingForQueryBuilder
        // Set conditions
        System::SharedPtr<ImapQueryBuilder> builder = System::MakeObject<ImapQueryBuilder>(System::Text::Encoding::get_UTF8());
        builder->get_Subject()->Contains(u"ğüşıöç", true);
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        // ExEnd:SpecifyEncodingForQueryBuilder
        
        // Get list of messages
        System::SharedPtr<ImapMessageInfoCollection> messages = client->ListMessages(query);
        
        {
            for (auto&& info : System::IterateOver(messages))
            {
                System::Console::WriteLine(System::String(u"Message Id: ") + info->get_MessageId());
            }
        }
        
        // Disconnect from IMAP
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}

