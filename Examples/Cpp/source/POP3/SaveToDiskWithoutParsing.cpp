#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Pop3/Pop3Client/Pop3Client.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Pop3;
using namespace Aspose::Email::Clients;

void SaveToDiskWithoutParsing()
{
    //ExStart:SaveToDiskWithoutParsing
    // The path to the File directory.
    System::String dataDir = GetDataDir_POP3();
    System::String dstEmail = dataDir + u"InsertHeaders.eml";
    
    // Create an instance of the Pop3Client class
    System::SharedPtr<Pop3Client> client = System::MakeObject<Pop3Client>();
    
    // Specify host, username, password, Port and SecurityOptions for your client
    client->set_Host(u"pop.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(995);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
    try
    {
        // Save message to disk by message sequence number
        client->SaveMessage(1, dstEmail);
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Retrieved email messages using POP3 ");
    //ExEnd:SaveToDiskWithoutParsing
}

