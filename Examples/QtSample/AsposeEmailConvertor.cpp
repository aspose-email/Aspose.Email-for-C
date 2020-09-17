#include "Aspose.Email.h"

#include <Tools/FileFormat/FileFormatUtil.h>
#include <Tools/FileFormat/FileFormatType.h>
#include <Tools/FileFormat/FileFormatInfo.h>
#include <TnefLoadOptions.h>
#include <HtmlSaveOptions.h>
#include <HtmlFormatOptions.h>
#include <Storage/Mbox/MboxrdStorageWriter.h>
#include <Storage/Pst/PersonalStorage.h>

using namespace Aspose::Email::Tools;
using namespace Aspose::Email;
using namespace Aspose::Email::Storage;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

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

System::SharedPtr<MapiMessage>  GetMailMessageFromStream(System::SharedPtr<System::IO::Stream> input)
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

void ConvertMIMEMessageToEML(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> output)
{
    auto message = MailMessage::Load(input);
    message->Save(output, SaveOptions::get_DefaultEml());
}

void ConvertEMLToMSG(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> output)
{
    auto message = MailMessage::Load(input, System::MakeObject<EmlLoadOptions>());
    message->Save(output, SaveOptions::get_DefaultMsgUnicode());
}

void ConvertMailToMbox(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> output)
{
    auto message = MailMessage::Load(input);
    auto writer = System::MakeObject<Mbox::MboxrdStorageWriter>(output, false);
    writer->WriteMessage(message);
}

void ConvertEmailToRtf(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> outputStream)
{
    auto mapi = GetMailMessageFromStream(input);
    auto writer = System::MakeObject<System::IO::StreamWriter>(outputStream);
    writer->Write(mapi->get_BodyRtf());
}

void ConvertMailToPst(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> outputStream)
{
    auto message = MailMessage::Load(input);
    //auto outputStream = handler->CreateOutputStream(System::IO::Path::ChangeExtension(shortResourceNameWithExtension, u".pst"));
    auto personalStorage = PersonalStorage::Create(outputStream, FileFormatVersion::Unicode);
    auto inbox = personalStorage->get_RootFolder()->AddSubFolder(u"Inbox");

    inbox->AddMessage(MapiMessage::FromMailMessage(message, MapiConversionOptions::get_UnicodeFormat()));
}

void ConvertEmailToTxt(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> outputStream)
{
    auto mapi = GetMailMessageFromStream(input);
    // auto outputStream = handler->CreateOutputStream(System::IO::Path::ChangeExtension(shortResourceNameWithExtension, u".txt"));
    auto writer = System::MakeObject<System::IO::StreamWriter>(outputStream);
    writer->Write(mapi->get_Body());
}

void ConvertEMLToMHT(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> outputStream)
{
    auto mail = MailMessage::Load(input, System::MakeObject<EmlLoadOptions>());
    auto mhtSaveOptions = System::MakeObject<MhtSaveOptions>();
    mhtSaveOptions->set_MhtFormatOptions(MhtFormatOptions::WriteHeader | MhtFormatOptions::HideExtraPrintHeader | MhtFormatOptions::DisplayAsOutlook);
    mhtSaveOptions->set_CheckBodyContentEncoding(true);

    //auto outputStream = handler->CreateOutputStream(System::IO::Path::ChangeExtension(shortResourceNameWithExtension, u".mht"));
    mail->Save(outputStream, mhtSaveOptions);
}

void ConvertEmailToHtml(System::SharedPtr<System::IO::Stream> input, System::SharedPtr<System::IO::Stream> outputStream)
{
    auto mail = MailMessage::Load(input, System::MakeObject<EmlLoadOptions>());
    auto htmlSaveOptions = System::MakeObject<HtmlSaveOptions>();
    htmlSaveOptions->set_HtmlFormatOptions(HtmlFormatOptions::WriteHeader | HtmlFormatOptions::DisplayAsOutlook);
    htmlSaveOptions->set_CheckBodyContentEncoding(true);

    //auto outputStream = handler->CreateOutputStream(System::IO::Path::ChangeExtension(shortResourceNameWithExtension, u".html"));
    mail->Save(outputStream, htmlSaveOptions);
}

void Convert(System::SharedPtr<System::IO::Stream> input, const std::string& shortResourceNameWithExtension, System::SharedPtr<System::IO::Stream> output, const std::string& outputType)
{
    if (outputType == "eml")
    {
        ConvertMIMEMessageToEML(input, output);
    }
    else if (outputType == "msg")
    {
        ConvertEMLToMSG(input, output);
    }
    else if (outputType == "mbox")
    {
        ConvertMailToMbox(input, output);
    }
    else if (outputType == "pst")
    {
        ConvertMailToPst(input, output);
    }
    else if (outputType == "mht")
    {
        ConvertEMLToMHT(input, output);
    }
    else if (outputType == "html")
    {
        ConvertEmailToHtml(input, output);
    }
/*
    else if (outputType == "svg" || outputType == "tiff")
    {
        ConvertEmailToSingleImage(input, shortResourceNameWithExtension, output, outputType);
    }
    else if (outputType == "jpg" || outputType == "bmp" || outputType == "png")
    {
        ConvertEmailToImages(input, shortResourceNameWithExtension, output, outputType);
    }
    else if (outputType == "pdf")
    {
        ConvertEmailToPdf(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "doc")
    {
        ConvertEmailToDoc(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "ppt")
    {
        ConvertEmailToPpt(input, shortResourceNameWithExtension, output);
    }
*/
    else if (outputType == "rtf")
    {
        ConvertEmailToRtf(input, output);
    }
/*
    else if (outputType == "docx")
    {
        ConvertEmailToDocx(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "docm")
    {
        ConvertEmailToDocm(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "dotx")
    {
        ConvertEmailToDotx(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "dotm")
    {
        ConvertEmailToDotm(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "odt")
    {
        ConvertEmailToOdt(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "ott")
    {
        ConvertEmailToOtt(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "epub")
    {
        ConvertEmailToEpub(input, shortResourceNameWithExtension, output);
    }
*/
    else if (outputType == "txt")
    {
        ConvertEmailToTxt(input, output);
    }
/*
    else if (outputType == "emf")
    {
        ConvertEmailToEmf(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "xps")
    {
        ConvertEmailToXps(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "pcl")
    {
        ConvertEmailToPcl(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "ps")
    {
        ConvertEmailToPs(input, shortResourceNameWithExtension, output);
    }
    else if (outputType == "mhtml")
    {
        ConvertEmailToMhtml(input, shortResourceNameWithExtension, output);
    }
*/
    else
    {
        throw System::NotSupportedException(u"Output type not supported {outputType?.ToUpperInvariant()}");
    }
}