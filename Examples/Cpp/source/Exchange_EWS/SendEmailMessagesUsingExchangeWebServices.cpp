#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
void SendEmailMessagesUsingExchangeWebServices()
{
    try
    {
        // Create instance of IEWSClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // Create instance of type MailMessage
        System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
        msg->set_From(MailAddress::to_MailAddress(u"sender@domain.com"));
        msg->set_To(MailAddressCollection::to_MailAddressCollection(u"recipient@ domain.com "));
        msg->set_Subject(u"Sending message from exchange server");
        msg->set_HtmlBody(u"<h3>sending message from exchange server</h3>");
        
        // Send the message
        client->Send(msg);
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex.get_Message());
    }
    
}
