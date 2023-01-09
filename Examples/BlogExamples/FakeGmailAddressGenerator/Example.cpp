//#include <system/string.h>
//#include <system/shared_ptr.h>
//#include <system/object.h>
#include "system/console.h"
#include <AttachmentCollection.h>
#include <Attachment.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <Licensing/License.h>

using namespace System;
using namespace Aspose::Email;

void LoadLicense(const String& licFile)
{
    try 
    {
        SharedPtr<License> license = System::MakeObject<License>();
        license->SetLicense(licFile);
    }
    catch (Exception& e)
    {
        Console::WriteLine(System::String(u"Failed to load license:") + e.ToString());
    }
}


int main()
{
    Console::WriteLine(u"Example running...");

    //LoadLicense(u"Aspose.Email.lic");

    // Create an instance of MailMessage class
    SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    message->set_From(u"sender@sender.com"); 
    
    message->get_To()->Add(u"receiver@gmail.com");

    message->Save(u"outputAttachments_out.msg", SaveOptions::get_DefaultMsgUnicode());

    Console::WriteLine(u"Example finished OK");
    return 0;
}
