/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string_comparison.h>
#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/special_casts.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/collections/icollection.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiNamedProperty.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <MailMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;


System::String GetNamedPropertyByAspose()
{
    //ExStart:ReadingNamedMAPIPropertyFromAttachment
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load from file
    System::SharedPtr<MailMessage> mail = MailMessage::Load(dataDir + u"outputAttachments.msg");
    
    auto mapi = MapiMessage::FromMailMessage(mail);
    
    
    {
        for (auto&& namedProperty : System::IterateOver<MapiNamedProperty>(mapi->get_Attachments()->idx_get(0)->get_NamedProperties()->get_Values()))
        {
            if (System::String::Compare(namedProperty->get_NameId(), u"CustomAttGuid", System::StringComparison::OrdinalIgnoreCase) == 0)
            {
                
                return namedProperty->GetString();
            }
        }
    }
    return System::String::Empty;
    //ExEnd:ReadingNamedMAPIPropertyFromAttachment
}

void ReadingNamedMAPIPropertyFromAttachment()
{
    System::String getProperty = GetNamedPropertyByAspose();
    System::Console::WriteLine(System::String(u"getProperty") + getProperty);
}
