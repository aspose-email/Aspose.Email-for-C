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
#include <MsgLoadOptions.h>
#include <MailMessage.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;

void ReadMessageByPreservingTNEFAttachments()
{
    // ExStart:ReadMessageByPreservingTNEFAttachments
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MsgLoadOptions> options = System::MakeObject<MsgLoadOptions>();
    options->set_PreserveTnefAttachments(true);
    System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir + u"EmbeddedImage1.msg", options);
    
    {
        for (auto&& attachment : System::IterateOver(eml->get_Attachments()))
        {
            System::Console::WriteLine(attachment->get_Name());
        }
    }
    // ExEnd:ReadMessageByPreservingTNEFAttachments
}






