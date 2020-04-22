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

void CountItemsInOLMFolder()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();

    System::SharedPtr<OlmStorage> storage = System::MakeObject<OlmStorage>(dataDir + u"SampleOLM.olm");
    for (auto folder : System::IterateOver(storage->get_FolderHierarchy()))
    {
        System::Console::WriteLine(System::String(u"Message Count [") + folder->get_Name() + u"]: " +
                                   folder->get_MessageCount());
    }
}
