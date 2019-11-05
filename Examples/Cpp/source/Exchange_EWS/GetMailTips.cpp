#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/console.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <Clients/Exchange/WebService/MailTips/ReplyBody.h>
#include <Clients/Exchange/WebService/MailTips/OutOfOfficeMailTip.h>
#include <Clients/Exchange/WebService/MailTips/MailTipsType.h>
#include <Clients/Exchange/WebService/MailTips/MailTips.h>
#include <Clients/Exchange/WebService/MailTips/GetMailTipsOptions.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
void GetMailTips()
{
    // Create instance of EWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    System::Console::WriteLine(u"Connected to Exchange server...");
    // Provide mail tips options
    System::SharedPtr<MailAddressCollection> addrColl = System::MakeObject<MailAddressCollection>();
    addrColl->Add(System::MakeObject<MailAddress>(u"test.exchange@ex2010.local", true));
    addrColl->Add(System::MakeObject<MailAddress>(u"invalid.recipient@ex2010.local", true));
    System::SharedPtr<GetMailTipsOptions> options = System::MakeObject<GetMailTipsOptions>(MailAddress::to_MailAddress(u"administrator@ex2010.local"), addrColl, Aspose::Email::Clients::Exchange::WebService::MailTipsType::All);
    
    try 
    {
        // Get Mail Tips
        System::ArrayPtr<System::SharedPtr<MailTips>> tips = client->GetMailTips(options);

        // Display information about each Mail Tip
        for (System::SharedPtr<MailTips> tip : tips)
        {
            // Display Out of office message, if present
            if (tip->get_OutOfOffice() != nullptr)
            {
                System::Console::WriteLine(System::String(u"Out of office: ") + tip->get_OutOfOffice()->get_ReplyBody()->get_Message());
            }

            // Display the invalid email address in recipient, if present
            if (tip->get_InvalidRecipient() == true)
            {
                System::Console::WriteLine(System::String(u"The recipient address is invalid: ") + tip->get_RecipientAddress());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

    
}
