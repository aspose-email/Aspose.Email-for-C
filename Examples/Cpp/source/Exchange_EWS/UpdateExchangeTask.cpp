#include "Examples.h"
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <net/network_credential.h>
#include <MailPriority.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTaskStatus.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTask.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void UpdateExchangeTask()
{

    try
    {

        // Create and initialize credentials
        auto credentials = System::MakeObject<System::Net::NetworkCredential>(u"username", u"12345");

        // Create instance of ExchangeClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

        // Get all tasks info collection from exchange
        System::SharedPtr<ExchangeMessageInfoCollection> tasks = client->ListMessages(client->get_MailboxInfo()->get_TasksUri());

        // Parse all the tasks info in the list
        for (auto info : System::IterateOver(tasks))
        {
            // Fetch task from exchange using current task info
            System::SharedPtr<ExchangeTask> task = client->FetchTask(info->get_UniqueUri());

            // Update the task status to NotStarted
            task->set_Status(Aspose::Email::Clients::Exchange::WebService::ExchangeTaskStatus::NotStarted);

            // Set the task due date
            task->set_DueDate(System::DateTime(2013, 2, 26));

            // Set task priority
            task->set_Priority(Aspose::Email::MailPriority::Low);

            // Update task on exchange
            client->UpdateTask(task);
        }

        System::Console::WriteLine(System::Environment::get_NewLine() + u"Task updated on Exchange Server successfully.");
    }
    catch (System::Exception& ex)
    {

        System::Console::Write(ex->get_Message());
    }
}