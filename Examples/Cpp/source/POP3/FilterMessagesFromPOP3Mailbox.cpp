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
#include <system/date_time.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Pop3/Pop3MessageInfoCollection.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Tools::Search;

void FilterMessagesFromPOP3Mailbox()
{
    // ExStart:FilterMessagesFromPOP3Mailbox
    // Connect and log in to POP3
    const System::String host = u"host";
    const int32_t port = 110;
    const System::String username = u"user@host.com";
    const System::String password = u"password";
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(host, port, username, password);
    
    // Set conditions, Subject contains "Newsletter", Emails that arrived today
    System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
    builder->get_Subject()->Contains(u"Newsletter");
    builder->get_InternalDate()->On(System::DateTime::get_Now());
    // Build the query and Get list of messages
    System::SharedPtr<MailQuery> query = builder->GetQuery();
    System::SharedPtr<Pop3MessageInfoCollection> messages = client->ListMessages(query);
    System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
    // ExEnd:FilterMessagesFromPOP3Mailbox
}

