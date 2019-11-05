#include "Examples.h"
#include <system/console.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTaskStatus.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTask.h>
#include <Calendar/Task_.h>

#include "Examples.h"

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;

void SaveExchangeTaskToDisc()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Exchange();
    System::String dstEmail = dataDir + u"Message.msg";
    
    System::SharedPtr<ExchangeTask> task = System::MakeObject<ExchangeTask>();
    task->set_Subject(System::String(u"TASK-ID - ") + System::Guid::NewGuid());
    task->set_Status(Aspose::Email::Clients::Exchange::WebService::ExchangeTaskStatus::InProgress);
    task->set_StartDate(System::DateTime::get_Now());
    task->set_DueDate(task->get_StartDate().AddDays(3));
    System::StaticCast<Calendar::Task>(task)->Save(dstEmail);
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Task saved on disk successfully at " + dstEmail);
}
