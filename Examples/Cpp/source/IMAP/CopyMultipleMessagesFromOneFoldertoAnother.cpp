/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <MailMessage.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void CopyMultipleMessagesFromOneFoldertoAnother()
{
    //ExStart:CopyMultipleMessagesFromOneFoldertoAnother
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"exchange.aspose.com", u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            // Create the destination folder
            System::String folderName = u"EMAILNET-35242";
            if (!client->ExistFolder(folderName))
            {
                client->CreateFolder(folderName);
            }
            
            {
                auto __finally_guard_0 = ::System::MakeScopeGuard([=]()
                {
                    try
                    {
                        client->DeleteFolder(folderName);
                    }
                    catch (...) { }
                    
                });
                
                try
                {
                    // Append a couple of messages to the server
                    System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"asposeemail.test3@aspose.com", u"asposeemail.test3@aspose.com", System::String(u"EMAILNET-35242 - ") + System::Guid::NewGuid(), u"EMAILNET-35242 Improvement of copy method.Add ability to 'copy' multiple messages per invocation.");
                    System::String uniqueId1 = client->AppendMessage(message1);
                    
                    System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"asposeemail.test3@aspose.com", u"asposeemail.test3@aspose.com", System::String(u"EMAILNET-35242 - ") + System::Guid::NewGuid(), u"EMAILNET-35242 Improvement of copy method.Add ability to 'copy' multiple messages per invocation.");
                    System::String uniqueId2 = client->AppendMessage(message2);
                    
                    // Verify that the messages have been added to the mailbox
                    client->SelectFolder(ImapFolderInfo::InBox);
                    System::SharedPtr<ImapMessageInfoCollection> msgsColl = client->ListMessages();
                    
                    {
                        for (auto&& msgInfo : System::IterateOver(msgsColl))
                        {
                            System::Console::WriteLine(msgInfo->get_Subject());
                        }
                    }
                    
                    // Copy multiple messages using the CopyMessages command and Verify that messages are copied to the destination folder
                    client->CopyMessages(System::MakeArray<System::String>({uniqueId1, uniqueId2}), folderName);
                    
                    client->SelectFolder(folderName);
                    msgsColl = client->ListMessages();
                    
                    {
                        for (auto&& msgInfo : System::IterateOver(msgsColl))
                        {
                            System::Console::WriteLine(msgInfo->get_Subject());
                        }
                    }
                }
                catch (...)
                {
                    throw;
                }
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    //ExEnd:CopyMultipleMessagesFromOneFoldertoAnother
}

