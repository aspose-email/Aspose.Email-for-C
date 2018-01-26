/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Mapi/MapiTaskUsers.h>
#include <Formats/Outlook/Mapi/MapiTaskOwnership.h>
#include <Formats/Outlook/Mapi/MapiTaskHistory.h>
#include <Formats/Outlook/Mapi/MapiTask.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void AddMapiTaskToPST()
{
    // The path to the File directory.
    // ExStart:AddMapiTaskToPST
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(L"To Do", L"Just click and type to add new task", System::DateTime::get_Now(), System::DateTime::get_Now().AddDays(3));
    task->set_PercentComplete(20);
    task->set_EstimatedEffort(2000);
    task->set_ActualEffort(20);
    task->set_History(Aspose::Email::Outlook::MapiTaskHistory::Assigned);
    task->set_LastUpdate(System::DateTime::get_Now());
    task->get_Users()->set_Owner(L"Darius");
    task->get_Users()->set_LastAssigner(L"Harkness");
    task->get_Users()->set_LastDelegate(L"Harkness");
    task->get_Users()->set_Ownership(Aspose::Email::Outlook::MapiTaskOwnership::AssignersCopy);
    
    System::String alreadyCreated = dataDir + L"AddMapiTaskToPST_out.pst";
    if (System::IO::File::Exists(alreadyCreated))
    {
        System::IO::File::Delete(alreadyCreated);
    }
    else { }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + L"AddMapiTaskToPST_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> taskFolder = personalStorage->CreatePredefinedFolder(L"Tasks", Aspose::Email::Outlook::Pst::StandardIpmFolder::Tasks);
        taskFolder->AddMapiMessageItem(task);
    }
    // ExEnd:AddMapiTaskToPST
}







