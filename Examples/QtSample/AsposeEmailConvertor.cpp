#include "Aspose.Email.h"

#include <Tools/FileFormatUtil.h>
#include <Tools/FileFormatType.h>
#include <Tools/FileFormatInfo.h>
#include <TnefLoadOptions.h>
#include <HtmlSaveOptions.h>

using namespace Aspose::Email::Tools;
using namespace Aspose::Email;

std::string getFileFormatType(const std::string& fileName)
{
    System::SharedPtr<FileFormatInfo> info = FileFormatUtil::DetectFileFormat(System::String::FromUtf8(fileName));

    return System::ObjectExt::ToString(info->get_FileFormatType()).ToUtf8String();
}

System::SharedPtr<MailMessage> GetMailMessageFromFile(const std::string&  fileNameUtf8)
{
    auto formatInfo = FileFormatUtil::DetectFileFormat(System::String::FromUtf8(fileNameUtf8));

    System::String fileNamePath = System::String::FromUtf8(fileNameUtf8);

    switch (formatInfo->get_FileFormatType())
    {
        case FileFormatType::Msg:
            return MailMessage::Load(fileNamePath, System::MakeObject<MsgLoadOptions>());
        case FileFormatType::Eml:
            return MailMessage::Load(fileNamePath, System::MakeObject<EmlLoadOptions>());
        case FileFormatType::Mht:
            return MailMessage::Load(fileNamePath, System::MakeObject<MhtmlLoadOptions>());
        case FileFormatType::Tnef:
            return MailMessage::Load(fileNamePath, System::MakeObject<TnefLoadOptions>());
        default:
            return nullptr;
    }
}

std::string MessageToHtml(System::SharedPtr<Aspose::Email::MailMessage> eml)
{
    System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
    System::String html = u"Failed to process message";

    try
    {
        eml->Save(ms, SaveOptions::get_DefaultHtml());
        html = System::Text::Encoding::get_ASCII()->GetString(ms->ToArray());
    }
    catch(...)
    {
    }

    return html.ToUtf8String();
}


std::string ConvertMailMessageToHtml(const std::string& fileName)
{
    std::string html = "<H1>File format not recognized";

    System::SharedPtr<MailMessage> message = GetMailMessageFromFile(fileName);

    if (message == nullptr)
    {
        return html;
    }

    return MessageToHtml(message);
}
