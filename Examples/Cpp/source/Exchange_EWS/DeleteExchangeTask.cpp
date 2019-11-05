#include "Examples.h"
#include <system/enumerator_adapter.h>
#include <Clients/Exchange/WebService/Tasks/ExchangeTask.h>
#include <Clients/Exchange/WebService/Tasks/DeleteTaskOptions.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMessageInfoCollection__.h>
#include <Clients/Exchange/ExchangeMessageInfo.h>
#include <Clients/Exchange/ExchangeMailboxInfo__.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;
void DeleteExchangeTask()
{
    // Create instance of IEWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    // Get all tasks info collection from exchange
    System::SharedPtr<ExchangeMessageInfoCollection> tasks = client->ListMessages(client->get_MailboxInfo()->get_TasksUri());

    // Parse all the tasks info in the list
    for (auto info : System::IterateOver(tasks))
    {
        // Fetch task from exchange using current task info
        System::SharedPtr<ExchangeTask> task = client->FetchTask(info->get_UniqueUri());

        // Check if the current task fulfills the search criteria
        if (System::ObjectExt::Equals(task->get_Subject(), u"test"))
        {
            // Delete task from exchange
            client->DeleteTask(task->get_UniqueUri(), Aspose::Email::Clients::Exchange::WebService::DeleteTaskOptions::DeletePermanently);
        }
    }

    System::Console::WriteLine(System::Environment::get_NewLine() + u"Task deleted on Exchange Server successfully.");

}
