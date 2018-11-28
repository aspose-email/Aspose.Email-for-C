/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
#include <system/console.h>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapIdentificationInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Clients;

void IMAP4IDExtensionSupport()
{
    //ExStart:IMAP4IDExtensionSupport
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.gmail.com", 993, u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ client});
        // ------------------------------------------
        
        try
        {
            // Set SecurityOptions
            client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
            System::Console::WriteLine(System::Convert::ToString(client->get_IdSupported()));
            
            System::SharedPtr<ImapIdentificationInfo> serverIdentificationInfo1 = client->IntroduceClient();
            System::SharedPtr<ImapIdentificationInfo> serverIdentificationInfo2 = client->IntroduceClient(ImapIdentificationInfo::get_DefaultValue());
            
            // Display ImapIdentificationInfo properties
            System::Console::WriteLine(System::ObjectExt::ToString(serverIdentificationInfo1), serverIdentificationInfo2);
            System::Console::WriteLine(serverIdentificationInfo1->get_Name());
            System::Console::WriteLine(serverIdentificationInfo1->get_Vendor());
            System::Console::WriteLine(serverIdentificationInfo1->get_SupportUrl());
            System::Console::WriteLine(serverIdentificationInfo1->get_Version());
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    //ExEnd:IMAP4IDExtensionSupport
}

