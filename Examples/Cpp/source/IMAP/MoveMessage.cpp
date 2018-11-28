#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <MailMessage.h>
#include <cstdint>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email;

void MoveMessage()
{
    // ExStart: MoveMessage
    /// <summary>
    /// This example shows how to move a message from one folder of a mailbox to another one using the ImapClient API of Aspose.Email for .NET
    /// Available from Aspose.Email for .NET 6.4.0 onwards
    /// -------------- Available API Overload Members --------------
    /// Void ImapClient.MoveMessage(IConnection iConnection, int sequenceNumber, string folderName, bool commitDeletions)
    /// Void ImapClient.MoveMessage(IConnection iConnection, string uniqueId, string folderName, bool commitDeletions)
    /// Void ImapClient.MoveMessage(int sequenceNumber, string folderName, bool commitDeletions)
    /// Void ImapClient.MoveMessage(string uniqueId, string folderName, bool commitDeletions)
    /// Void ImapClient.MoveMessage(IConnection iConnection, int sequenceNumber, string folderName)
    /// Void ImapClient.MoveMessage(IConnection iConnection, string uniqueId, string folderName)
    /// Void ImapClient.MoveMessage(int sequenceNumber, string folderName)
    /// Void ImapClient.MoveMessage(string uniqueId, string folderName)
    /// </summary>
    
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"host.domain.com", 993, u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ client});
        // ------------------------------------------
        
        try
        {
            System::String folderName = u"EMAILNET-35151";
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
                    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@domain.com", System::String(u"EMAILNET-35151 - ") + System::Guid::NewGuid(), u"EMAILNET-35151 ImapClient: Provide option to Move Message");
                    client->SelectFolder(ImapFolderInfo::InBox);
                    // Append the new message to Inbox folder
                    System::String uniqueId = client->AppendMessage(ImapFolderInfo::InBox, message);
                    System::SharedPtr<ImapMessageInfoCollection> messageInfoCol1 = client->ListMessages();
                    System::Console::WriteLine(messageInfoCol1->get_Count());
                    // Now move the message to the folder EMAILNET-35151
                    client->MoveMessage(uniqueId, folderName);
                    client->CommitDeletes();
                    // Verify that the message was moved to the new folder
                    client->SelectFolder(folderName);
                    messageInfoCol1 = client->ListMessages();
                    System::Console::WriteLine(messageInfoCol1->get_Count());
                    // Verify that the message was moved from the Inbox
                    client->SelectFolder(ImapFolderInfo::InBox);
                    messageInfoCol1 = client->ListMessages();
                    System::Console::WriteLine(messageInfoCol1->get_Count());
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
    // ExEnd: MoveMessage
}

