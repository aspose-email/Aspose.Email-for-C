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
#include <system/io/stream.h>
#include <system/io/path.h>
#include <system/io/memory_stream.h>
#include <system/io/file.h>
#include <system/enum_helpers.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <Mime/ContentType.h>
#include <MailMessageSaveType.h>
#include <MailMessage.h>
#include <LinkedResourceCollection.h>
#include <LinkedResource.h>
#include <FileCompatibilityMode.h>
#include <EmlSaveOptions.h>
#include <cstdint>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mime;


void UpdateResources(System::SharedPtr<MailMessage> msg, System::String imgFileName)
{
    for (int32_t i = 0; i < msg->get_Attachments()->get_Count(); i++)
    {
        if ((msg->get_Attachments()->idx_get(i)->get_ContentType()->get_MediaType() == u"image/png") || (msg->get_Attachments()->idx_get(i)->get_ContentType()->get_MediaType() == u"application/octet-stream" && System::IO::Path::GetExtension(msg->get_Attachments()->idx_get(i)->get_ContentType()->get_Name()) == u".jpg"))
        {
            msg->get_Attachments()->idx_get(i)->set_ContentStream(System::MakeObject<System::IO::MemoryStream>(System::IO::File::ReadAllBytes(imgFileName)));
        }
        else if ((msg->get_Attachments()->idx_get(i)->get_ContentType()->get_MediaType() == u"message/rfc822") || (msg->get_Attachments()->idx_get(i)->get_ContentType()->get_MediaType() == u"application/octet-stream" && System::IO::Path::GetExtension(msg->get_Attachments()->idx_get(i)->get_ContentType()->get_Name()) == u".msg"))
        {
            System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
            msg->get_Attachments()->idx_get(i)->Save(ms);
            ms->set_Position(0);
            System::SharedPtr<MailMessage> embeddedMessage = MailMessage::Load(ms);
            UpdateResources(embeddedMessage, imgFileName);
            System::SharedPtr<System::IO::MemoryStream> msProcessedEmbedded = System::MakeObject<System::IO::MemoryStream>();
            embeddedMessage->Save(msProcessedEmbedded, SaveOptions::get_DefaultMsgUnicode());
            msProcessedEmbedded->set_Position(0);
            msg->get_Attachments()->idx_get(i)->set_ContentStream(msProcessedEmbedded);
        }
    }
    
    
    {
        auto att_enumerator = (msg->get_LinkedResources())->GetEnumerator();
        decltype(att_enumerator->get_Current()) att;
        while (att_enumerator->MoveNext() && (att = att_enumerator->get_Current(), true))
        {
            if (att->get_ContentType()->get_MediaType() == u"image/png")
            {
                att->set_ContentStream(System::MakeObject<System::IO::MemoryStream>(System::IO::File::ReadAllBytes(imgFileName)));
            }
        }
    }
}

void TestUpdateResources(System::String dataDir)
{
    System::String fileName = dataDir + u"tnefEML1.eml";
    System::String imgFileName = dataDir + u"Untitled.jpg";
    System::String outFileName = dataDir + u"UpdateTNEFAttachments_out.eml";
    System::SharedPtr<MailMessage> originalMailMessage = MailMessage::Load(fileName);
    UpdateResources(originalMailMessage, imgFileName);
    System::SharedPtr<EmlSaveOptions> emlSo = System::MakeObject<EmlSaveOptions>(MailMessageSaveType::get_EmlFormat());
    emlSo->set_FileCompatibilityMode(Aspose::Email::FileCompatibilityMode::PreserveTnefAttachments);
    originalMailMessage->Save(outFileName, emlSo);
}

void UpdateTNEFAttachments()
{
    System::String dataDir = GetDataDir_Email();
    TestUpdateResources(dataDir);
}






