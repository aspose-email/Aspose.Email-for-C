#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <MsgLoadOptions.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

#include "Examples.h"

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;

void SendTaskRequestUsingIEWSClient()
{
    try
    {
        System::String dataDir = GetDataDir_Exchange();
        // Create instance of ExchangeClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        System::SharedPtr<MsgLoadOptions> options = System::MakeObject<MsgLoadOptions>();
        options->set_PreserveTnefAttachments(true);
        
        // load task from .msg file
        System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir + u"task.msg", options);
        eml->set_From(MailAddress::to_MailAddress(u"firstname.lastname@domain.com"));
        eml->get_To()->Clear();
        eml->get_To()->Add(System::MakeObject<MailAddress>(u"firstname.lastname@domain.com"));
        client->Send(eml);
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex->get_Message());
    }
    
}
