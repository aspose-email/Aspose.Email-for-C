﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email;

void AddingNewMessage()
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
        //ExStart:AddingNewMessageToFolder
        // Create a message
        System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>(u"user@domain1.com", u"user@domain2.com", u"subject", u"message");
        
        // Subscribe to the Inbox folder and Append the newly created message
        client->SelectFolder(ImapFolderInfo::InBox);
        client->SubscribeFolder(client->get_CurrentFolder()->get_Name());
        client->AppendMessage(client->get_CurrentFolder()->get_Name(), msg);
        //ExEnd:AddingNewMessageToFolder
        
        System::Console::WriteLine(u"New Message Added Successfully");
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Added new message on IMAP server.");
}

