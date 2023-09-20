/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/nullable.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <Mapi/BodyContentType.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

bool IsInlineAttachment(System::SharedPtr<Aspose::Email::Mapi::MapiAttachment> att, System::SharedPtr<Aspose::Email::Mapi::MapiMessage> msg)
{
    switch (msg->get_BodyType())
    {
        case Aspose::Email::Mapi::BodyContentType::PlainText:
            return false;
        
        case Aspose::Email::Mapi::BodyContentType::Html:
            if (att->get_Properties()->ContainsKey(0x37140003))
            {
                System::Nullable<int64_t> attachFlagsValue = att->GetPropertyLong(0x37140003);
                if (attachFlagsValue != nullptr && (attachFlagsValue & 0x00000004) == 0x00000004)
                {
                    // check PidTagAttachContentId property
                    if (att->get_Properties()->ContainsKey(MapiPropertyTag::PR_ATTACH_CONTENT_ID) || att->get_Properties()->ContainsKey(MapiPropertyTag::PR_ATTACH_CONTENT_ID_W))
                    {
                        System::String contentId = att->get_Properties()->ContainsKey(MapiPropertyTag::PR_ATTACH_CONTENT_ID) ? att->get_Properties()->idx_get(MapiPropertyTag::PR_ATTACH_CONTENT_ID)->GetString() : att->get_Properties()->idx_get(MapiPropertyTag::PR_ATTACH_CONTENT_ID_W)->GetString();
                        if (msg->get_BodyHtml().Contains(contentId))
                        {
                            return true;
                        }
                    }
                    // check PidTagAttachContentLocation property
                    if (att->get_Properties()->ContainsKey(0x3713001E) || att->get_Properties()->ContainsKey(0x3713001F))
                    {
                        return true;
                    }
                }
                else if ((att->get_Properties()->ContainsKey(0x3716001F) && att->GetPropertyString(0x3716001F) == u"inline") || (att->get_Properties()->ContainsKey(0x3716001E) && att->GetPropertyString(0x3716001E) == u"inline"))
                {
                    return true;
                }
            }
            else if ((att->get_Properties()->ContainsKey(0x3716001F) && att->GetPropertyString(0x3716001F) == u"inline") || (att->get_Properties()->ContainsKey(0x3716001E) && att->GetPropertyString(0x3716001E) == u"inline"))
            {
                return true;
            }
            return false;
        
        case Aspose::Email::Mapi::BodyContentType::Rtf:
            if (att->get_Properties()->ContainsKey(MapiPropertyTag::PR_ATTACH_METHOD))
            {
                return att->GetPropertyLong(MapiPropertyTag::PR_ATTACH_METHOD) == 0x00000006;
            }
            return false;
        
        default: 
            throw System::ArgumentOutOfRangeException();
        
    }
}


void IdentifyInlineAndRegularAttachments()
{
    System::String dataDir = GetDataDir_Email();
    auto message = MapiMessage::Load(dataDir + u"RemoveAttachments.msg");
    auto attachments = message->get_Attachments();
    int32_t count = attachments->get_Count();

    System::Console::WriteLine(System::String(u"Total attachments ") + count);
    for (int32_t i = 0; i < attachments->get_Count(); i++)
    {
        auto attachment = attachments->idx_get(i);
        if (IsInlineAttachment(attachment, message))
        {
            System::Console::WriteLine(attachment->get_LongFileName() + u" is inline attachment");
        }
        else
        {
            System::Console::WriteLine(attachment->get_LongFileName() + u" is regular attachment");
        }
    }

}




