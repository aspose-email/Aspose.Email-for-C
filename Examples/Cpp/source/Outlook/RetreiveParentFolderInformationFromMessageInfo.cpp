/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void RetreiveParentFolderInformationFromMessageInfo()
{
    // ExStart:RetreiveParentFolderInformationFromMessageInfo
    // Load Pst File
    System::String dataDir = GetDataDir_Outlook() + L"PersonalStorage.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        auto folder_enumerator = (personalStorage->get_RootFolder()->GetSubFolders())->GetEnumerator();
        decltype(folder_enumerator->get_Current()) folder;
        while (folder_enumerator->MoveNext() && (folder = folder_enumerator->get_Current(), true))
        {
            auto msg_enumerator = (folder->EnumerateMessages())->GetEnumerator();
            decltype(msg_enumerator->get_Current()) msg;
            while (msg_enumerator->MoveNext() && (msg = msg_enumerator->get_Current(), true))
            {
                System::SharedPtr<FolderInfo> fi = personalStorage->GetParentFolder(msg->get_EntryId());
            }
        }
    }
    // ExEnd:RetreiveParentFolderInformationFromMessageInfo
}







