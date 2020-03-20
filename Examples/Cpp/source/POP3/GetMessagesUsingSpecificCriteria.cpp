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
#include <Clients/Pop3/Pop3MessageInfoCollection.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Tools::Search;

void GetMessagesUsingSpecificCriteria()
{
    // Connect and log in to POP3
    const System::String host = u"host";
    const int32_t port = 110;
    const System::String username = u"user@host.com";
    const System::String password = u"password";
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>(host, port, username, password);
    
    try
    {
        
        // ExStart:GetEmailsWithTodayDate
        // Emails that arrived today
        System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
        builder->get_InternalDate()->On(System::DateTime::get_Now());
        // ExEnd:GetEmailsWithTodayDate
        
        // Build the query and Get list of messages
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<Pop3MessageInfoCollection> messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:GetEmailsOverDateRange
        // Emails that arrived in last 7 days
        builder->get_InternalDate()->Before(System::DateTime::get_Now());
        builder->get_InternalDate()->Since(System::DateTime::get_Now().AddDays(-7));
        // ExEnd:GetEmailsOverDateRange
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:GetSpecificSenderEmails
        // Get emails from specific sender
        builder->get_From()->Contains(u"saqib.razzaq@127.0.0.1");
        // ExEnd:GetSpecificSenderEmails
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:GetSpecificDomainEmails
        // Get emails from specific domain
        builder->get_From()->Contains(u"SpecificHost.com");
        // ExEnd:GetSpecificDomainEmails
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
        
        builder = System::MakeObject<MailQueryBuilder>();
        
        // ExStart:GetSpecificRecipientEmails
        // Get emails sent to specific recipient
        builder->get_To()->Contains(u"recipient");
        // ExEnd:GetSpecificRecipientEmails
        
        // Build the query and Get list of messages
        query = builder->GetQuery();
        messages = client->ListMessages(query);
        System::Console::WriteLine(System::String(u"Pop3: ") + messages->get_Count() + u" message(s) found.");
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}

