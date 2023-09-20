#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mapi/MapiRecipientType.h>
#include <Mapi/MapiRecipientCollection.h>
#include <Mapi/MapiRecipient.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email::Mapi;

void RecipientInformation()
{
    // ExStart:RecipientInformation
    // The path to the File directory.
    System::String dataDir = GetDataDir_POP3();
    System::String dstEmail = dataDir + u"Message.msg";
    
    // Load message file and Enumerate the recipients
    System::SharedPtr<MapiMessage> message = MapiMessage::Load(dstEmail);
    
    {
        for (auto&& recip : System::IterateOver(message->get_Recipients()))
        {
            switch (recip->get_RecipientType())
            {
                case Aspose::Email::Mapi::MapiRecipientType::MAPI_TO:
                    System::Console::WriteLine(u"RecipientType:TO");
                    break;
                
                case Aspose::Email::Mapi::MapiRecipientType::MAPI_CC:
                    System::Console::WriteLine(u"RecipientType:CC");
                    break;
                
                case Aspose::Email::Mapi::MapiRecipientType::MAPI_BCC:
                    System::Console::WriteLine(u"RecipientType:BCC");
                    break;
                
            }
            // Get email address, display name and  address type
            System::Console::WriteLine(System::String(u"Email Address: ") + recip->get_EmailAddress());
            System::Console::WriteLine(System::String(u"DisplayName: ") + recip->get_DisplayName());
            System::Console::WriteLine(System::String(u"AddressType: ") + recip->get_AddressType());
        }
    }
    // ExEnd:RecipientInformation
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Displayed recipient information from MSG file " + dstEmail);
}

