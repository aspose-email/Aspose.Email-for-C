#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/list_ext.h>
#include <Storage/Olm/OlmStorage.h>
#include <Storage/Olm/OlmFolder.h>
#include <cstdint>

#include <Storage/Olm/OlmStorage.h>
#include <Storage/Olm/OlmFolder.h>
#include <Exceptions/TraversalExceptionsCallback.h>

#include "Examples.h"

using namespace Aspose::Email::Storage::Olm;
using namespace Aspose::Email::Exceptions;
using namespace System;


void ExtractItems(System::SharedPtr<Aspose::Email::Storage::Olm::OlmStorage> storage, System::SharedPtr<System::Collections::Generic::ListExt<System::SharedPtr<Aspose::Email::Storage::Olm::OlmFolder>>> folders)
{
    for (auto&& folder : System::IterateOver(folders))
    {
        if (folder->get_HasMessages())
        {
            Console::WriteLine(folder);

            int32_t count = 0;

            for (auto&& msg : System::IterateOver(storage->EnumerateMessages(folder)))
            {
                Console::WriteLine(msg->get_Subject());
            }
        }

        if (folder->get_SubFolders()->get_Count() > 0)
        {
            ExtractItems(storage, folder->get_SubFolders());
        }
    }
}


void TraversalExceptionsFunc(TraversalAsposeException e, System::String id)
{
    Console::Write(u"TraversalExceptions: ");
    Console::WriteLine(e->get_Message());
}

void ReadCorruptedOLM()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + u"Corrupted.olm";

    System::SharedPtr<OlmStorage> storage = System::MakeObject<OlmStorage>(TraversalExceptionsFunc);
    
    storage->Load(fileName);
    
    System::SharedPtr<System::Collections::Generic::ListExt<System::SharedPtr<OlmFolder>>> folderHierarchy = storage->GetFolders();
    
    ExtractItems(storage, folderHierarchy);
    
}
