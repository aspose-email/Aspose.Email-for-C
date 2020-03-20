#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MailConversionOptions.h>
#include <MailMessage.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/WebService/Delegate/ExchangeDelegateUser.h>
#include <Clients/Exchange/WebService/Delegate/ExchangeDelegatePermissions.h>
#include <Clients/Exchange/WebService/Delegate/ExchangeDelegateFolderPermissionLevel.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Mapi;

void SendCalendarInvitation()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    try
    {
        // delegate calendar access permission
        System::SharedPtr<ExchangeDelegateUser> delegateUser = System::MakeObject<ExchangeDelegateUser>(u"sharingfrom@domain.com", Aspose::Email::Clients::Exchange::WebService::ExchangeDelegateFolderPermissionLevel::NotSpecified);
        delegateUser->get_FolderPermissions()->set_CalendarFolderPermissionLevel(Aspose::Email::Clients::Exchange::WebService::ExchangeDelegateFolderPermissionLevel::Reviewer);
        client->DelegateAccess(delegateUser, u"sharingfrom@domain.com");

        // Create invitation
        System::SharedPtr<MapiMessage> mapiMessage = client->CreateCalendarSharingInvitationMessage(u"sharingfrom@domain.com");
        System::SharedPtr<MailConversionOptions> options = System::MakeObject<MailConversionOptions>();
        options->set_ConvertAsTnef(true);
        System::SharedPtr<MailMessage> mail = mapiMessage->ToMailMessage(options);
        client->Send(mail);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}