/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/Imap/Search/ImapQueryBuilder.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;

void ListMessagesWithMaximumNumberOfMessages()
{
    // ExStart:ListMessagesWithMaximumNumberOfMessages
    // Create an imapclient with host, user and password
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"localhost", u"user", u"password");
    
    // Select the inbox folder and Get the message info collection
    System::SharedPtr<ImapQueryBuilder> builder = System::MakeObject<ImapQueryBuilder>();
    System::SharedPtr<MailQuery> query = builder->Or(builder->Or(builder->Or(builder->Or(builder->get_Subject()->Contains(u" (1) "), builder->get_Subject()->Contains(u" (2) ")), builder->get_Subject()->Contains(u" (3) ")), builder->get_Subject()->Contains(u" (4) ")), builder->get_Subject()->Contains(u" (5) "));
    System::SharedPtr<ImapMessageInfoCollection> messageInfoCol4 = client->ListMessages(query, 4);
    System::Console::WriteLine((messageInfoCol4->get_Count() == 4) ? System::String(u"Success") : System::String(u"Failure"));
    // ExEnd:ListMessagesWithMaximumNumberOfMessages
}

