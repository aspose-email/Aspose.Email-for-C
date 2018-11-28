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
#include <Tools/Search/DateComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;

void BuildingComplexQueries()
{
    // Connect and log in to POP3
    const System::String host = u"host";
    const int32_t port = 143;
    const System::String username = u"user@host.com";
    const System::String password = u"password";
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(host, port, username, password);
    
    try
    {
        System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:CombineQueriesWithAND
        // Emails from specific host, get all emails that arrived before today and all emails that arrived since 7 days ago
        builder->get_From()->Contains(u"SpecificHost.com");
        builder->get_InternalDate()->Before(System::DateTime::get_Now());
        builder->get_InternalDate()->Since(System::DateTime::get_Now().AddDays(-7));
        // ExEnd:CombineQueriesWithAND
        
        // Build the query and Get list of messages
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<ImapMessageInfoCollection> messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Imap: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:CombiningQueriesWithOR
        // Specify OR condition
        builder->Or(builder->get_Subject()->Contains(u"test"), builder->get_From()->Contains(u"noreply@host.com"));
        // ExEnd:CombiningQueriesWithOR
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Imap: ") + messages->get_Count() + u" message(s) found.");
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}

