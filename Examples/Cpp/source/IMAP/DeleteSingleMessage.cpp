/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
#include <system/console.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void DeleteSingleMessage()
{
    //ExStart:DeleteSingleMessage
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"exchange.aspose.com", u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            
            {
                auto __finally_guard_0 = ::System::MakeScopeGuard([=]() { });
                
                try
                {
                    System::Console::WriteLine(System::Convert::ToString(client->get_UidPlusSupported()));
                    // Append some test messages
                    client->SelectFolder(ImapFolderInfo::InBox);
                    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"from@Aspose.com", u"to@Aspose.com", System::String(u"EMAILNET-35227 - ") + System::Guid::NewGuid(), u"EMAILNET-35227 Add ability in ImapClient to delete message");
                    System::String emailId = client->AppendMessage(message);
                    
                    // Now verify that all the messages have been appended to the mailbox
                    System::SharedPtr<ImapMessageInfoCollection> messageInfoCol;
                    messageInfoCol = client->ListMessages();
                    System::Console::WriteLine(messageInfoCol->get_Count());
                    
                    // Select the inbox folder and Delete message
                    client->SelectFolder(ImapFolderInfo::InBox);
                    client->DeleteMessage(emailId);
                    client->CommitDeletes();
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
    //ExEnd:DeleteSingleMessage
}

