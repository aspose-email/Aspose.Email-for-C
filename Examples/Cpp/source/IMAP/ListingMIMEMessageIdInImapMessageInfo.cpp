/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;

void ListingMIMEMessageIdInImapMessageInfo()
{
    // ExStart:ListingMIMEMessageIdInImapMessageInfo
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    client->set_Host(u"domain.com");
    client->set_Username(u"username");
    client->set_Password(u"password");
    
    try
    {
        System::SharedPtr<ImapMessageInfoCollection> messageInfoCol = client->ListMessages(u"Inbox");
        
        {
            auto info_enumerator = (messageInfoCol)->GetEnumerator();
            decltype(info_enumerator->get_Current()) info;
            while (info_enumerator->MoveNext() && (info = info_enumerator->get_Current(), true))
            {
                // Display MIME Message ID
                System::Console::WriteLine(System::String(u"Message Id = ") + info->get_MessageId());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
    // ExEnd:ListingMIMEMessageIdInImapMessageInfo
}

