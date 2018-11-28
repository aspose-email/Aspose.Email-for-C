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
#include <system/iasyncresult.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3MessageInfoCollection.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Tools::Search;

void ListMessagesAsynchronouslyWithMailQuery()
{
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    client->set_Host(u"pop.gmail.com");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLImplicit);
    client->set_Username(u"username");
    client->set_Password(u"password");
    
    try
    {
        // ExStart:ListMessagesAsynchronouslyWithMailQuery
        System::SharedPtr<MailQueryBuilder> builder = System::MakeObject<MailQueryBuilder>();
        builder->get_Subject()->Contains(u"Subject");
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<System::IAsyncResult> asyncResult = client->BeginListMessages(query);
        System::SharedPtr<Pop3MessageInfoCollection> messages = client->EndListMessages(asyncResult);
        // ExEnd:ListMessagesAsynchronouslyWithMailQuery
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}

