//using Aspose.Email.Outlook;
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void DestroyAttachment()
{
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"MsgWithAtt.msg");
    msg->Save(dataDir + L"AttachmentsToDestroy_out.msg");
    
    // ExStart:DestroyAttachment
    MapiMessage::DestroyAttachments(dataDir + L"AttachmentsToDestroy_out.msg");
    // ExEnd:DestroyAttachment
}







