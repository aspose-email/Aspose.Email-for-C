﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <MailMessage.h>
#include <EmlLoadOptions.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;

void ExtractAttachments()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance of MailMessage and load an email file
    System::SharedPtr<MailMessage> mailMsg = MailMessage::Load(dataDir + u"Test.eml", System::MakeObject<EmlLoadOptions>());
    
    
    for (auto&& attachment : System::IterateOver(mailMsg->get_Attachments()))
    {
        // To display the the attachment file name
        attachment->Save(dataDir + u"ExtractAttachments_out." + attachment->get_Name());
            
        System::Console::WriteLine(attachment->get_Name());
    }
}






