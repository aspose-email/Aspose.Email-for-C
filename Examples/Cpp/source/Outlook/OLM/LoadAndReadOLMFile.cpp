#include <Mapi/MapiMessage.h>
#include <Storage/Olm/OlmFolder.h>
#include <Storage/Olm/OlmStorage.h>
#include <cstdint>
#include <system/collections/ienumerable.h>
#include <system/collections/list.h>
#include <system/console.h>
#include <system/details/dispose_guard.h>
#include <system/enumerator_adapter.h>
#include <system/object.h>
#include <system/shared_ptr.h>
#include <system/string.h>

#include <Storage/Olm/OlmFolder.h>
#include <Storage/Olm/OlmStorage.h>

#include "Examples.h"

using namespace Aspose::Email::Storage::Olm;
using namespace Aspose::Email::Mapi;

void LoadAndReadOLMFile()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"SampleOLM.olm";

    System::SharedPtr<OlmStorage> storage = System::MakeObject<OlmStorage>(dst);

    for (auto folder : System::IterateOver(storage->get_FolderHierarchy()))
    {
        if (folder->get_HasMessages())
        {
            // extract messages from folder
            for (auto msg : System::IterateOver(storage->EnumerateMessages(folder)))
            {
                System::Console::WriteLine(System::String(u"Subject: ") + msg->get_Subject());
            }
        }

        // read sub-folders
        if (folder->get_SubFolders()->get_Count() > 0)
        {
            for (auto sub_folder : System::IterateOver(folder->get_SubFolders()))
            {
                System::Console::WriteLine(System::String(u"Subfolder: ") + sub_folder->get_Name());
            }
        }
    }
}
