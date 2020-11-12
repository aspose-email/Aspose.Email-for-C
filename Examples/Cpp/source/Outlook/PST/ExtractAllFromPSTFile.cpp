#include <Mapi/MapiMessage.h>
#include <MsgSaveOptions.h>
#include <SaveOptions.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/PersonalStorage.h>
#include <cstdint>
#include <system/collections/ienumerable.h>
#include <system/collections/ilist.h>
#include <system/console.h>
#include <system/date_time.h>
#include <system/enumerator_adapter.h>
#include <system/io/directory.h>
#include <system/io/path.h>
#include <system/object.h>
#include <system/random.h>
#include <system/shared_ptr.h>
#include <system/string.h>

#include "Examples.h"

using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

System::String GetFileName(System::String subject, System::DateTime time)
{
    System::SharedPtr<System::Random> r = System::MakeObject<System::Random>();
    System::String fileName;

    if (System::String::IsNullOrEmpty(subject))
    {
        fileName = u"NoSubject";
        return fileName + u"_" + r->Next(1, 1000);
    }

    fileName = time.ToString(u"yyyy-MM-dd HHmmss") + u"_";

    for (char16_t t : subject)
    {
        if (t > 31 && t < 127)
        {
            fileName += t;
        }
    }

    fileName = fileName.Replace(u"\\", u"_")
                   .Replace(u"/", u"_")
                   .Replace(u":", u"_")
                   .Replace(u"*", u"_")
                   .Replace(u"?", u"_")
                   .Replace(u"\"", u"_")
                   .Replace(u"<", u"_")
                   .Replace(u">", u"_")
                   .Replace(u"|", u"_")
                   .Replace(u"\n", u"")
                   .Replace(u"\r", u"")
                   .Replace(u"\t", u"")
                   .Replace(u"\u000e", u"");

    return fileName + u"_" + r->Next(1, 100000);
}

void SaveMessages(System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst, System::String parenFolderId,
                  System::String currentFolder)
{
    for (auto messageId : System::IterateOver(pst->FindMessages(parenFolderId)))
    {
        try
        {
            System::SharedPtr<MapiMessage> msg = pst->ExtractMessage(messageId);
            msg->Save(
                System::IO::Path::Combine(currentFolder, GetFileName(msg->get_Subject(), msg->get_DeliveryTime())) +
                    u".msg",
                Aspose::Email::SaveOptions::get_DefaultMsgUnicode());
        }
        catch (...)
        {
            System::Console::WriteLine(u"Extract message error");
        }
    }
}

void XstExtract(System::SharedPtr<Aspose::Email::Storage::Pst::FolderInfo> folderInfo,
    System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst, System::String folder,
    int32_t& corruptedCount);

void HandleCorruptedFolders(System::String parentFolderEntryId,
    System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst, System::String folder,
    int32_t& corruptedCount)
{
    System::SharedPtr<System::Collections::Generic::IList<System::String>> sufFolders =
        pst->FindSubfolders(parentFolderEntryId);

    for (auto entryId : System::IterateOver(sufFolders))
    {
        try
        {
            auto subfolderInfo = pst->GetFolderById(entryId);
            XstExtract(subfolderInfo, pst, folder, System::Ref(corruptedCount));
        }
        catch (...)
        {
            corruptedCount++;

            System::String currentFolder =
                System::IO::Path::Combine(folder, System::String(u"Corrupted") + corruptedCount);

            if (!System::IO::Directory::Exists(currentFolder))
            {
                System::IO::Directory::CreateDirectory_(currentFolder);
            }

            SaveMessages(pst, entryId, currentFolder);

            HandleCorruptedFolders(entryId, pst, currentFolder, System::Ref(corruptedCount));
        }
    }
}

void XstExtract(System::SharedPtr<Aspose::Email::Storage::Pst::FolderInfo> folderInfo,
                System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst, System::String folder,
                int32_t& corruptedCount)
{
    System::String currentFolder = System::IO::Path::Combine(folder, folderInfo->get_DisplayName());

    if (!System::IO::Directory::Exists(currentFolder))
    {
        System::IO::Directory::CreateDirectory_(currentFolder);
    }

    SaveMessages(pst, folderInfo->get_EntryIdString(), currentFolder);

    if (folderInfo->get_HasSubFolders())
    {
        try
        {
            for (auto subfolderInfo : System::IterateOver(folderInfo->EnumerateFolders()))
            {
                XstExtract(subfolderInfo, pst, currentFolder, System::Ref(corruptedCount));
            }
        }
        catch (...)
        {
            HandleCorruptedFolders(folderInfo->get_EntryIdString(), pst, currentFolder, System::Ref(corruptedCount));
        }
    }
}


void ExtractAllFromPSTFile()
{
    // ExStart:DisplayInformationOfPSTFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"Outlook.pst";

    // load PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dst);

    // Get the folders information
    System::SharedPtr<FolderInfoCollection> folderInfoCollection = personalStorage->get_RootFolder()->GetSubFolders();

    // Browse through each folder to display folder name and number of messages
    for (auto folderInfo : System::IterateOver(folderInfoCollection))
    {
        System::Console::WriteLine(System::String(u"Folder: ") + folderInfo->get_DisplayName());
        System::Console::WriteLine(System::String(u"Total items: ") + folderInfo->get_ContentCount());
        System::Console::WriteLine(System::String(u"Total unread items: ") + folderInfo->get_ContentUnreadCount());
        System::Console::WriteLine(u"-----------------------------------");
    }
    // ExEnd:DisplayInformationOfPSTFile

    // extract PST content into filesystem in MSG files
    System::SharedPtr<FolderInfo> rootFolderInfo = personalStorage->get_RootFolder();

    int32_t corruptedCount = 0;

    XstExtract(rootFolderInfo, personalStorage, dataDir + u"ExtractAllFromPSTFile", System::Ref(corruptedCount));

    System::Console::WriteLine(u"-----------------------------------");
    System::Console::WriteLine(System::String(u"Corrupted items: ") + corruptedCount);
    System::Console::WriteLine(u"-----------------------------------");
}
