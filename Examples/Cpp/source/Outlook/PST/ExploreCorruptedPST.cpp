#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/enumerator_adapter.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ilist.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Storage::Pst;

void ExploreCorruptedPst(System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst, System::String rootFolderId)
{
    auto messageIdList = pst->FindMessages(rootFolderId);
    
    for (auto messageId : System::IterateOver(messageIdList))
    {
        try
        {
            auto msg = pst->ExtractMessage(messageId);
            System::Console::WriteLine(System::String(u"- ") + msg->get_Subject());
        }
        catch (...)
        {
            System::Console::WriteLine(System::String(u"Message reading error. Entry id: ") + messageId);
        }
    }
    
    auto folderIdList = pst->FindSubfolders(rootFolderId);
    
    for (auto subFolderId : System::IterateOver(folderIdList))
    {
        if (subFolderId != rootFolderId)
        {
            try
            {
                System::SharedPtr<FolderInfo> subfolder = pst->GetFolderById(subFolderId);
                System::Console::WriteLine(subfolder->get_DisplayName());
            }
            catch (...)
            {
                System::Console::WriteLine(System::String(u"Message reading error. Entry id: ") + subFolderId);
            }
            ExploreCorruptedPst(pst, subFolderId);
        }
    }
}

void ExploreCorruptedPST()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"Outlook.pst";
    
    auto pst = PersonalStorage::FromFile(fileName);
    ExploreCorruptedPst(pst, pst->get_RootFolder()->get_EntryIdString());
}
