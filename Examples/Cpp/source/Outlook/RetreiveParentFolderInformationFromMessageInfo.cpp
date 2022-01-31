/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void RetreiveParentFolderInformationFromMessageInfo()
{
    // ExStart:RetreiveParentFolderInformationFromMessageInfo
    // Load Pst File
    System::String dataDir = GetDataDir_Outlook() + u"PersonalStorage.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            for (auto&& folder : personalStorage->get_RootFolder()->GetSubFolders())
            {
                for (auto&& msg : System::IterateOver(folder->EnumerateMessages()))
                {
                    System::SharedPtr<FolderInfo> fi = personalStorage->GetParentFolder(msg->get_EntryId());
                }
            }
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:RetreiveParentFolderInformationFromMessageInfo
}

