#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/read_only_collection.h>
#include <Mime/HeaderCollection.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Mime;
using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void RetrievingEmailHeaders()
{
    // ExStart:RetrievingEmailHeaders
    // Create an instance of the Pop3Client class
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    
    // Specify host, username. password, Port and SecurityOptions for your client
    client->set_Host(u"pop.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");

    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
        
    try
    {
        System::SharedPtr<HeaderCollection> headers = client->GetMessageHeaders(1);
        for (int32_t i = 0; i < headers->get_Count(); i++)
        {
            // Display key and value in the header collection
            System::Console::Write(headers->get_Keys()->idx_get(i));
            System::Console::Write(u" : ");
            System::Console::WriteLine(headers->Get(i));
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

    // ExEnd:RetrievingEmailHeaders
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Displayed header information from emails using POP3 ");
}
