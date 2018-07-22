/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <Storage/Pst/StandardIpmFolder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>
#include <Mapi/MapiTaskUsers.h>
#include <Mapi/MapiTaskOwnership.h>
#include <Mapi/MapiTaskHistory.h>
#include <Mapi/MapiTask.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void AddMapiTaskToPST()
{
    // The path to the File directory.
    // ExStart:AddMapiTaskToPST
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiTask> task = System::MakeObject<MapiTask>(u"To Do", u"Just click and type to add new task", System::DateTime::get_Now(), System::DateTime::get_Now().AddDays(3));
    task->set_PercentComplete(20);
    task->set_EstimatedEffort(2000);
    task->set_ActualEffort(20);
    task->set_History(Aspose::Email::Mapi::MapiTaskHistory::Assigned);
    task->set_LastUpdate(System::DateTime::get_Now());
    task->get_Users()->set_Owner(u"Darius");
    task->get_Users()->set_LastAssigner(u"Harkness");
    task->get_Users()->set_LastDelegate(u"Harkness");
    task->get_Users()->set_Ownership(Aspose::Email::Mapi::MapiTaskOwnership::AssignersCopy);
    
    System::String alreadyCreated = dataDir + u"AddMapiTaskToPST_out.pst";
    if (System::IO::File::Exists(alreadyCreated))
    {
        System::IO::File::Delete(alreadyCreated);
    }
    else { }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::Create(dataDir + u"AddMapiTaskToPST_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> taskFolder = personalStorage->CreatePredefinedFolder(u"Tasks", Aspose::Email::Storage::Pst::StandardIpmFolder::Tasks);
            taskFolder->AddMapiMessageItem(task);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:AddMapiTaskToPST
}

