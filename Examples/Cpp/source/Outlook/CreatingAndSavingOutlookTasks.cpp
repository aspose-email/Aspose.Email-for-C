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
#include <system/date_time.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/Messaging/Enums/MapiSensitivity.h>
#include <Formats/Outlook/Mapi/TaskSaveFormat.h>
#include <Formats/Outlook/Mapi/MapiTaskUsers.h>
#include <Formats/Outlook/Mapi/MapiTaskStatus.h>
#include <Formats/Outlook/Mapi/MapiTaskOwnership.h>
#include <Formats/Outlook/Mapi/MapiTaskHistory.h>
#include <Formats/Outlook/Mapi/MapiTask.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;
using namespace Aspose::Email::Outlook;


void CreatingAndSavingOutlookTasks()
{
    // ExStart:CreatingAndSavingOutlookTasks
    // The path to the File directory.
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
    task->set_Companies(System::MakeArray<System::String>({L"company1", L"company2", L"company3"}));
    task->set_Categories(System::MakeArray<System::String>({L"category1", L"category2", L"category3"}));
    task->set_Mileage(L"Some test mileage");
    task->set_Billing(L"Test billing information");
    task->get_Users()->set_Delegator(L"Test Delegator");
    task->set_Sensitivity(Aspose::Email::Outlook::Pst::MapiSensitivity::Personal);
    task->set_Status(Aspose::Email::Outlook::MapiTaskStatus::Complete);
    task->set_EstimatedEffort(5);
    task->Save(dataDir + L"MapiTask.msg", Aspose::Email::Outlook::TaskSaveFormat::Msg);
    // ExEnd:CreatingAndSavingOutlookTasks
}







