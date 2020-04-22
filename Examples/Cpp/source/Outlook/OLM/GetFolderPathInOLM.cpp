#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <Storage/Olm/OlmStorage.h>
#include <Storage/Olm/OlmFolder.h>
#include <cstdint>

#include <Storage/Olm/OlmStorage.h>
#include <Storage/Olm/OlmFolder.h>

#include "Examples.h"

using namespace Aspose::Email::Storage::Olm;

void PrintPath(
    System::SharedPtr<Aspose::Email::Storage::Olm::OlmStorage> storage,
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Aspose::Email::Storage::Olm::OlmFolder>>>
        folders)
{
    for (auto folder : System::IterateOver(folders))
    {
        // print the current folder path
        System::Console::WriteLine(folder->get_Path());

        if (folder->get_SubFolders()->get_Count() > 0)
        {
            PrintPath(storage, folder->get_SubFolders());
        }
    }
}

void GetFolderPathInOLM()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();

    System::SharedPtr<OlmStorage> storage = System::MakeObject<OlmStorage>(dataDir + u"SampleOLM.olm");
    PrintPath(storage, storage->get_FolderHierarchy());
}
