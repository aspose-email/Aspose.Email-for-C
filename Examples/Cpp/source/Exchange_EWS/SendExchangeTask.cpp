#include "Examples.h"
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlLoadOptions.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

#include "Examples.h"

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
void SendExchangeTask()
{
    
    try
    {
        
        // The path to the File directory.
        System::String dataDir = GetDataDir_Exchange();
        System::String dstEmail = dataDir + u"Message.eml";
        
        // Create instance of ExchangeClient class by giving credentials
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        
        // load task from .eml file
        System::SharedPtr<EmlLoadOptions> loadOptions = System::MakeObject<EmlLoadOptions>();
        
        loadOptions->set_PrefferedTextEncoding(System::Text::Encoding::get_UTF8());
        loadOptions->set_PreserveTnefAttachments(true);
        
        // load task from .msg file
        System::SharedPtr<MailMessage> eml = MailMessage::Load(dstEmail, loadOptions);
        eml->set_From(MailAddress::to_MailAddress(u"firstname.lastname@domain.com"));
        eml->get_To()->Clear();
        eml->get_To()->Add(System::MakeObject<MailAddress>(u"firstname.lastname@domain.com"));
        client->Send(eml);
        System::Console::WriteLine(System::Environment::get_NewLine() + u"Task sent on Exchange Server successfully.");
    }
    catch (System::Exception& ex)
    {
        
        System::Console::Write(ex->get_Message());
    }
    
}
