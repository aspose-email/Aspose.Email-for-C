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
#include <system/date_time.h>
#include <system/array.h>
#include <Storage/Pst/MapiSensitivity.h>
#include <Mapi/TaskSaveFormat.h>
#include <Mapi/MapiTaskUsers.h>
#include <Mapi/MapiTaskStatus.h>
#include <Mapi/MapiTaskOwnership.h>
#include <Mapi/MapiTaskHistory.h>
#include <Mapi/MapiTask.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;
using namespace Aspose::Email::Mapi;

void CreatingAndSavingOutlookTasks()
{
    // ExStart:CreatingAndSavingOutlookTasks
    // The path to the File directory.
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
    task->set_Companies(System::MakeArray<System::String>({u"company1", u"company2", u"company3"}));
    task->set_Categories(System::MakeArray<System::String>({u"category1", u"category2", u"category3"}));
    task->set_Mileage(u"Some test mileage");
    task->set_Billing(u"Test billing information");
    task->get_Users()->set_Delegator(u"Test Delegator");
    task->set_Sensitivity(Aspose::Email::Storage::Pst::MapiSensitivity::Personal);
    task->set_Status(Aspose::Email::Mapi::MapiTaskStatus::Complete);
    task->set_EstimatedEffort(5);
    task->Save(dataDir + u"MapiTask.msg", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    // ExEnd:CreatingAndSavingOutlookTasks
}

