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
#include <Mapi/TaskSaveFormat.h>
#include <Mapi/MapiTask.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void AddReminderInformationToMapiTask()
{
    // ExStart:AddReminderInformationToMapiTask
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create MapiTask and set Task Properties
    System::SharedPtr<MapiTask> testTask = System::MakeObject<MapiTask>(u"task with reminder", u"this is a body", System::DateTime::get_Now(), System::DateTime::get_Now().AddHours(1));
    testTask->set_ReminderSet(true);
    testTask->set_ReminderTime(System::DateTime::get_Now());
    testTask->set_ReminderFileParameter(dataDir + u"Alarm01.wav");
    testTask->Save(dataDir + u"AddReminderInformationToMapiTask_out", Aspose::Email::Mapi::TaskSaveFormat::Msg);
    // ExEnd:AddReminderInformationToMapiTask
}

