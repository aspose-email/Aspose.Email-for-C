#include "system/io/file.h"
#include "system/io/memory_stream.h"

#include <MailMessage.h>
#include <Tools/FileFormat/FileFormatUtil.h>
#include <Tools/FileFormat/FileFormatType.h>
#include <Tools/FileFormat/FileFormatInfo.h>
#include <TnefLoadOptions.h>
#include <HtmlSaveOptions.h>
#include <HtmlFormatOptions.h>
#include <MsgLoadOptions.h>
#include <EmlLoadOptions.h>
#include <MhtmlLoadOptions.h>
#include <EmlSaveOptions.h>
#include <MsgSaveOptions.h>
#include <Storage/Mbox/MboxrdStorageWriter.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiMessage.h>
#include <MhtSaveOptions.h>
#include <Storage/Pst/FolderInfo.h>
#include <MhtFormatOptions.h>
#include <Mapi/MapiConversionOptions.h>
#include <Licensing/License.h>

#include "AsposeEmailConvetor.h"

using namespace System::IO;
using namespace Aspose::Email::Tools;
using namespace Aspose::Email;
using namespace Aspose::Email::Storage;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

std::string LoadLicense(std::string licenseFileName)
{
    std::string result = "OK";
    System::String licFile = System::String::FromUtf8(licenseFileName.c_str());
    System::SharedPtr<License> license = System::MakeObject<License>();
    try 
    {
        license->SetLicense(licFile);
    }
    catch (System::Exception& exc)
    {
        result = exc->get_Message().ToUtf8String();
    }
    return result;
}


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

System::SharedPtr<MapiMessage>  GetMapiMessageFromStream(System::SharedPtr<System::IO::Stream> input)
{
    auto formatInfo = FileFormatUtil::DetectFileFormat(input);
    input->set_Position(0);

    switch (formatInfo->get_FileFormatType())
    {
        case FileFormatType::Msg:
            return MapiMessage::Load(input, System::MakeObject<MsgLoadOptions>());
        case FileFormatType::Eml:
            return MapiMessage::Load(input, System::MakeObject<EmlLoadOptions>());
        case FileFormatType::Mht:
            return MapiMessage::Load(input, System::MakeObject<MhtmlLoadOptions>());
        case FileFormatType::Tnef:
            return MapiMessage::Load(input, System::MakeObject<TnefLoadOptions>());
        default:
            return nullptr;
    }
}

System::SharedPtr<MapiMessage>  GetMapiMessageFromFile(const std::string&  fileNameUtf8)
{
    auto formatInfo = FileFormatUtil::DetectFileFormat(System::String::FromUtf8(fileNameUtf8));
    System::String fileNamePath = System::String::FromUtf8(fileNameUtf8);

    switch (formatInfo->get_FileFormatType())
    {
        case FileFormatType::Msg:
            return MapiMessage::Load(fileNamePath, System::MakeObject<MsgLoadOptions>());
        case FileFormatType::Eml:
            return MapiMessage::Load(fileNamePath, System::MakeObject<EmlLoadOptions>());
        case FileFormatType::Mht:
            return MapiMessage::Load(fileNamePath, System::MakeObject<MhtmlLoadOptions>());
        case FileFormatType::Tnef:
            return MapiMessage::Load(fileNamePath, System::MakeObject<TnefLoadOptions>());
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
    std::string html;

    try {
        System::SharedPtr<MailMessage> message = GetMailMessageFromFile(fileName);

        if (message == nullptr)
        {
            return "FAILED";
        }
        System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();

        message->Save(ms, SaveOptions::get_DefaultHtml());
        html = System::Text::Encoding::get_ASCII()->GetString(ms->ToArray()).ToAsciiString();
    }
    catch (System::Exception& exc)
    {
        std::string message = exc->get_Message().ToUtf8String();
        return "FAILED: " + message;
    }

    return html;
}

void Convert(const std::string& fileName, const std::string& outputFileName, const std::string& outputType)
{
    System::SharedPtr<System::IO::Stream> output = File::Open(System::String::FromUtf8(outputFileName), FileMode::OpenOrCreate);

    if (outputType == "eml")
    {
        auto message = GetMailMessageFromFile(fileName);
        message->Save(output, SaveOptions::get_DefaultEml());
    }
    else if (outputType == "msg")
    {
        auto message = GetMailMessageFromFile(fileName);
        message->Save(output, SaveOptions::get_DefaultMsgUnicode());
    }
    else if (outputType == "mbox")
    {
        auto message = GetMailMessageFromFile(fileName);
        auto writer = System::MakeObject<Mbox::MboxrdStorageWriter>(output, false);
        writer->WriteMessage(message);
    }
    else if (outputType == "pst")
    {
        auto message = GetMailMessageFromFile(fileName);
        auto personalStorage = PersonalStorage::Create(output, FileFormatVersion::Unicode);
        auto inbox = personalStorage->get_RootFolder()->AddSubFolder(u"Inbox");

        inbox->AddMessage(MapiMessage::FromMailMessage(message, MapiConversionOptions::get_UnicodeFormat()));

    }
    else if (outputType == "mht")
    {
        auto message = GetMailMessageFromFile(fileName);
        auto mhtSaveOptions = System::MakeObject<MhtSaveOptions>();
        mhtSaveOptions->set_MhtFormatOptions(MhtFormatOptions::WriteHeader | MhtFormatOptions::HideExtraPrintHeader | MhtFormatOptions::DisplayAsOutlook);
        mhtSaveOptions->set_CheckBodyContentEncoding(true);

        message->Save(output, mhtSaveOptions);

    }
    else if (outputType == "html")
    {
        auto message = GetMailMessageFromFile(fileName);
        auto htmlSaveOptions = System::MakeObject<HtmlSaveOptions>();
        htmlSaveOptions->set_HtmlFormatOptions(HtmlFormatOptions::WriteHeader | HtmlFormatOptions::DisplayAsOutlook);
        htmlSaveOptions->set_CheckBodyContentEncoding(true);

        message->Save(output, htmlSaveOptions);

    }
    else if (outputType == "rtf")
    {
        auto mapi = GetMapiMessageFromFile(fileName);
        auto writer = System::MakeObject<System::IO::StreamWriter>(output);
        writer->Write(mapi->get_BodyRtf());

    }
    else if (outputType == "txt")
    {
        auto mapi = GetMapiMessageFromFile(fileName);
        auto writer = System::MakeObject<System::IO::StreamWriter>(output);
        writer->Write(mapi->get_Body());
    }
    else
    {
        throw System::NotSupportedException(u"Output type not supported {outputType?.ToUpperInvariant()}");
    }
}


std::string ConvertMailMessageFile(const std::string& fileName, const std::string& outputFileName, const std::string& outputType)
{
    try
    {
        Convert(fileName, outputFileName, outputType);
    }
    catch (System::Exception& exc)
    {
        std::string message = exc->get_Message().ToUtf8String();
        return "FAILED: " + message;
    }

    return "OK";
}
