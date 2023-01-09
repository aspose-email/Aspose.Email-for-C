#include <MailAddress.h>

#include <Clients/SecurityOptions.h>

#include <Clients/Imap/ImapClient/ImapClient.h>
#include <Clients/Imap/Search/ImapQueryBuilder.h>

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/BoolComparisonField.h>

#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapMessageFlags.h>




using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;


void ProcessGmailMailbox(System::SharedPtr<MailAddress> originalAddress, System::SharedPtr<MailAddress> generatedAddress)
{

    auto imapClient = System::MakeObject<Clients::Imap::ImapClient>(
        u"imap.gmail.com", 993, originalAddress->get_User(), u"password",
        SecurityOptions::SSLAuto);
       
    imapClient->SelectFolder(u"INBOX");
    auto queryBuilder = System::MakeObject<ImapQueryBuilder>();
    queryBuilder->get_To()->Contains(generatedAddress->get_Address());

    auto list = imapClient->ListMessages(queryBuilder->GetQuery());

    if (list->get_Count() > 0)
    {
    //Mark as read
        imapClient->AddMessageFlags(list, ImapMessageFlags::get_IsRead());
    //Move
        imapClient->MoveMessages(list, u"DestinationFolder");
    //Remove
        imapClient->DeleteMessages(list, true);
    }
}
