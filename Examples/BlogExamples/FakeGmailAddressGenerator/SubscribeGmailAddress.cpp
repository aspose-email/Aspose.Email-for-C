#include <functional>
#include <system/enumerator_adapter.h>

#include "system/console.h"

#include <MailAddressCollection.h>

#include <Clients/Imap/ImapMonitoringEventArgs.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include <Clients/Imap/ImapMonitoringErrorEventArgs.h>
#include <Clients/Imap/ImapMessageFlags.h>
#include <Clients/SecurityOptions.h>


using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;

void MonitorGmailMailbox(System::SharedPtr<MailAddress> originalAddress, System::SharedPtr<MailAddress> generatedAddress)
{
    auto imapClient = System::MakeObject<Clients::Imap::ImapClient>(
        u"imap.gmail.com", 993, originalAddress->get_User(), u"password",
        SecurityOptions::SSLAuto);


    std::function<void(System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringEventArgs> eventArgs)> subscribeCallback =
    [&generatedAddress, &imapClient](System::SharedPtr<System::Object> sender, System::SharedPtr<ImapMonitoringEventArgs> eventArgs)
    {
        auto newMessages = eventArgs->get_NewMessages();
        auto generated = System::MakeObject<ImapMessageInfoCollection>();
        for (auto newMessage : IterateOver(newMessages))
        {
            System::SharedPtr<MailAddressCollection> recepients = newMessage->get_To();
            for (auto address : IterateOver(newMessage->get_To()))
            {
                if (address->get_Address() == generatedAddress->get_Address())
                {
                    generated->Add(newMessage);
                    break;
                }
            }
        }
        if (generated->get_Count() == 0) return;

        imapClient->SelectFolder(u"INBOX");

        //Do something with the received messages. For example, mark them as read:
        imapClient->AddMessageFlags(generated, ImapMessageFlags::get_IsRead());

        //or delete them
        imapClient->DeleteMessages(generated, true);
    };

    std::function<void(System::SharedPtr<System::Object> sender, System::SharedPtr<Clients::Imap::ImapMonitoringErrorEventArgs> eventArgs)> errorCallback =
    [](System::SharedPtr<System::Object> _, System::SharedPtr<ImapMonitoringErrorEventArgs> errorEventArgs)
    {
        Console::WriteLine(errorEventArgs->get_Error()->get_Message());
    };

    imapClient->StartMonitoring(subscribeCallback, errorCallback, u"INBOX");

}