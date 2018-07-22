#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include "system/console.h"
#include <AttachmentCollection.h>
#include <Attachment.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>

using namespace System;
using namespace Aspose::Email;

int main()
{
    Console::WriteLine(L"Example running...");

    // Create an instance of MailMessage class
    SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    message->set_From(u"sender@sender.com");
    
    message->get_To()->Add(u"receiver@gmail.com");

    message->Save(u"outputAttachments_out.msg", SaveOptions::get_DefaultMsgUnicode());

    Console::WriteLine(L"Example finished OK");
    return 0;
}
