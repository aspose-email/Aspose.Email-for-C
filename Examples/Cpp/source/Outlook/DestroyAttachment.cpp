﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void DestroyAttachment()
{
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiMessage> msg = MapiMessage::Load(dataDir + u"MsgWithAtt.msg");
    msg->Save(dataDir + u"AttachmentsToDestroy_out.msg");
    
    // ExStart:DestroyAttachment
    MapiMessage::DestroyAttachments(dataDir + u"AttachmentsToDestroy_out.msg");
    // ExEnd:DestroyAttachment
}

