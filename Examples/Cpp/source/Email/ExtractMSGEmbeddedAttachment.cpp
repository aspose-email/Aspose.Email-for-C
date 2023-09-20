/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
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
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiObjectProperty.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

bool IsAttachmentInline(System::SharedPtr<Aspose::Email::Mapi::MapiAttachment> attachment)
{
    
    {
        for (auto&& property : System::IterateOver(attachment->get_ObjectData()->get_Properties()->get_Values()))
        {
            if (property->get_Name() == u"\x0003" u"ObjInfo")
            {
                uint16_t odtPersist1 = System::BitConverter::ToUInt16(property->get_Data(), 0);
                return (odtPersist1 & (1 << (7 - 1))) == 0;
            }
        }
    }
    return false;
}

void SaveAttachment(System::SharedPtr<Aspose::Email::Mapi::MapiAttachment> attachment, System::String fileName)
{
    for (auto&& property : System::IterateOver(attachment->get_ObjectData()->get_Properties()->get_Values()))
    {
        if (property->get_Name() == u"Package")
        {
            {
                System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(fileName, System::IO::FileMode::Create, System::IO::FileAccess::Write);
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard<1> __dispose_guard_0({ fs});
                // ------------------------------------------
                
                try
                {
                    fs->Write(property->get_Data(), 0, property->get_Data()->get_Length());
                }
                catch(...)
                {
                    __dispose_guard_0.SetCurrentException(std::current_exception());
                }
            }
        }
    }
}

void ExtractInlineAttachments(System::String dataDir)
{
    System::SharedPtr<MapiMessage> message = MapiMessage::Load(dataDir + u"MSG file with RTF Formatting.msg");
    System::SharedPtr<MapiAttachmentCollection> attachments = message->get_Attachments();

    {
        for (auto&& attachment : attachments)
        {

            if (IsAttachmentInline(attachment))
            {
                try
                {
                    SaveAttachment(attachment, System::ObjectExt::ToString(System::Guid()));
                }
                catch (System::Exception& ex)
                {
                    System::Console::WriteLine(ex->get_Message());
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





