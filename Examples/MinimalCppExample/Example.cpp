#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include "system/console.h"
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>

using namespace System;
using namespace Aspose::Email::Mail;

int main()
{
    Console::WriteLine(L"Example running...");

    // Create an instance of MailMessage class
    SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    message->set_From(L"sender@sender.com");
    
    message->get_To()->Add(L"receiver@gmail.com");

    message->Save(L"outputAttachments_out.msg", SaveOptions::get_DefaultMsgUnicode());

    Console::WriteLine(L"Example finished OK");
    return 0;
}
