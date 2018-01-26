/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string_comparison.h>
#include <system/string.h>
#include <system/special_casts.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/collections/icollection.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiNamedProperty.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


System::String GetNamedPropertyByAspose()
{
    //ExStart:ReadingNamedMAPIPropertyFromAttachment
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();

    // Load from file
    System::SharedPtr<MailMessage> mail = MailMessage::Load(dataDir + L"outputAttachments.msg");

    auto mapi = MapiMessage::FromMailMessage(mail);


    {
        auto namedProperty_enumerator = (System::DynamicCastEnumerableTo<System::SharedPtr<MapiNamedProperty>>(mapi->get_Attachments()->idx_get(0)->get_NamedProperties()->get_Values()))->GetEnumerator();
        decltype(namedProperty_enumerator->get_Current()) namedProperty;
        while (namedProperty_enumerator->MoveNext() && (namedProperty = namedProperty_enumerator->get_Current(), true))
        {
            if (System::String::Compare(namedProperty->get_NameId(), L"CustomAttGuid", System::StringComparison::OrdinalIgnoreCase) == 0)
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
    System::Console::WriteLine(System::String(L"getProperty") + getProperty);
}








