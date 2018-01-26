/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/collections/icollection.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiObjectProperty.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;




bool IsAttachmentInline(System::SharedPtr<Aspose::Email::Outlook::MapiAttachment> attachment)
{
    
    {
        auto property_enumerator = (attachment->get_ObjectData()->get_Properties()->get_Values())->GetEnumerator();
        decltype(property_enumerator->get_Current()) property;
        while (property_enumerator->MoveNext() && (property = property_enumerator->get_Current(), true))
        {
            if (property->get_Name() == L"\x0003" L"ObjInfo")
            {
                uint16_t odtPersist1 = System::BitConverter::ToUInt16(property->get_Data(), 0);
                return (odtPersist1 & (1 << (7 - 1))) == 0;
            }
        }
    }
    return false;
}

void SaveAttachment(System::SharedPtr<Aspose::Email::Outlook::MapiAttachment> attachment, System::String fileName)
{
    auto property_enumerator = (attachment->get_ObjectData()->get_Properties()->get_Values())->GetEnumerator();
    decltype(property_enumerator->get_Current()) property;
    while (property_enumerator->MoveNext() && (property = property_enumerator->get_Current(), true))
    {
        if (property->get_Name() == L"Package")
        {
            {
                System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(fileName, System::IO::FileMode::Create, System::IO::FileAccess::Write);
                
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard __dispose_guard_0{ fs, ASPOSE_CURRENT_FUNCTION_LINE };
                // ------------------------------------------
                fs->Write(property->get_Data(), 0, property->get_Data()->get_Length());
            }
        }
    }
}

void ExtractInlineAttachments(System::String dataDir)
{
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(dataDir + L"MSG file with RTF Formatting.msg");
    System::SharedPtr<MapiAttachmentCollection> attachments = message->get_Attachments();

    {
        auto attachment_enumerator = (attachments)->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {

            if (IsAttachmentInline(attachment))
            {
                try
                {
                    SaveAttachment(attachment, System::ObjectExt::ToString(System::Guid()));
                }
                catch (System::Exception& ex)
                {
                    System::Console::WriteLine(ex.get_Message());
                }

            }
        }
    }
}

void ExtractMSGEmbeddedAttachment()
{
    System::String dataDir = GetDataDir_Email();
    ExtractInlineAttachments(dataDir);
}



