#include "Examples.h"
#include <system/threading/thread.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/idictionary.h>
#include <system/array.h>
#include <MailMessage.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Imap;
void RetrieveExtraParametersAsSummaryInformation()
{
    try
    {
        {
            System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"host.domain.com", u"username", u"password");
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>(u"from@domain.com", u"to@doman.com", System::String(u"EMAILNET-38466 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()), u"EMAILNET-38466 Add extra parameters for UID FETCH command");
                
                // append the message to the server
                System::String uid = client->AppendMessage(message);
                
                // wait for the message to be appended
                System::Threading::Thread::Sleep(5000);
                
                // Define properties to be fetched from server along with the message
                System::ArrayPtr<System::String> messageExtraFields = System::MakeArray<System::String>({u"X-GM-MSGID", u"X-GM-THRID"});
                
                // retreive the message summary information using it's UID
                System::SharedPtr<ImapMessageInfo> messageInfoUID = client->ListMessage(uid, messageExtraFields);
                
                // retreive the message summary information using it's sequence number
                System::SharedPtr<ImapMessageInfo> messageInfoSeqNum = client->ListMessage(1, messageExtraFields);
                
                // List messages in general from the server based on the defined properties
                System::SharedPtr<ImapMessageInfoCollection> messageInfoCol = client->ListMessages(messageExtraFields);
                
                System::SharedPtr<ImapMessageInfo> messageInfoFromList = messageInfoCol->idx_get(0);
                
                // verify that the parameters are fetched in the summary information
                for (System::String paramName : messageExtraFields)
                {
                    System::Console::WriteLine(messageInfoFromList->get_ExtraParameters()->ContainsKey(paramName));
                    System::Console::WriteLine(messageInfoUID->get_ExtraParameters()->ContainsKey(paramName));
                    System::Console::WriteLine(messageInfoSeqNum->get_ExtraParameters()->ContainsKey(paramName));
                }
                
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
    }
    
}
