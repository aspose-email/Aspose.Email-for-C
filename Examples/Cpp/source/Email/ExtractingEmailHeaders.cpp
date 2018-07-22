#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mime/HeaderCollection.h>
#include <MailMessage.h>
#include <EmlLoadOptions.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mime;

void ExtractingEmailHeaders()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:ExtractingEmailHeaders
    System::SharedPtr<MailMessage> message;
    
    // Create MailMessage instance by loading an EML file
    message = MailMessage::Load(dataDir + u"email-headers.eml", System::MakeObject<EmlLoadOptions>());
    System::Console::WriteLine(u"\n\nheaders:\n\n");
    
    // Print out all the headers
    int32_t index = 0;
    
    {
        auto header_enumerator = (message->get_Headers())->GetEnumerator();
        decltype(header_enumerator->get_Current()) header;
        while (header_enumerator->MoveNext() && (header = header_enumerator->get_Current(), true))
        {
            System::Console::Write(header + u" - ");
            System::Console::WriteLine(message->get_Headers()->Get(index++));
        }
    }
    // ExEnd:ExtractingEmailHeaders
}






