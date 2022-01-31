/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapMessageFlags.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void SetCustomFlag()
{
    // Create an instance of the ImapClient class
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    
    // Specify host, username, password, port and SecurityOptions for your client
    client->set_Host(u"imap.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(993);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    try
    {
        //ExStart:SetCustomFlag
        // Create a message
        System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"user@domain1.com", u"user@domain2.com", u"subject", u"message");
        
        //Append the message to mailbox
        System::String uid = client->AppendMessage(ImapFolderInfo::InBox, message);
        
        //Add custom flags to the added messge
        client->AddMessageFlags(uid, ImapMessageFlags::Keyword(u"custom1") | ImapMessageFlags::Keyword(u"custom1_0"));
        
        //Retreive the messages for checking the presence of custom flag
        client->SelectFolder(ImapFolderInfo::InBox);
        
        System::SharedPtr<ImapMessageInfoCollection> messageInfos = client->ListMessages();
        
        {
            for (auto&& inf : System::IterateOver(messageInfos))
            {
                System::ArrayPtr<System::SharedPtr<ImapMessageFlags>> flags = inf->get_Flags()->Split();
                
                if (inf->ContainsKeyword(u"custom1"))
                {
                    System::Console::WriteLine(u"Keyword found");
                }
            }
        }
        
        //ExEnd:SetCustomFlag
        
        System::Console::WriteLine(u"Setting Custom Flag to Message example executed successfully!");
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
}

