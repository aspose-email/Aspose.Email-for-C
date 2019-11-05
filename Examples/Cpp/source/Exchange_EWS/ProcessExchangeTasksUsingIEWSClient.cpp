#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTaskStatus.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTask.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
void ProcessExchangeTasksUsingIEWSClient()
{
    // Create instance of EWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    // Create Exchange task object
    System::SharedPtr<ExchangeTask> task = System::MakeObject<ExchangeTask>();
    
    // Set task subject and status to In progress
    task->set_Subject(u"New-Test");
    task->set_Status(Aspose::Email::Clients::Exchange::WebService::ExchangeTaskStatus::InProgress);
    client->CreateTask(client->get_MailboxInfo()->get_TasksUri(), task);
}
