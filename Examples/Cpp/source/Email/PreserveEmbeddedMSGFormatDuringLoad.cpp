/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/FileFormat/FileFormatUtil.h>
#include <Tools/FileFormat/FileFormatType.h>
#include <Tools/FileFormat/FileFormatInfo.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/console.h>
#include <MailMessage.h>
#include <EmlLoadOptions.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Tools;

void PreserveEmbeddedMSGFormatDuringLoad()
{
    //ExStart: PreserveEmbeddedMSGFormatDuringLoad
    System::String dataDir = GetDataDir_Email();
    
    System::SharedPtr<MailMessage> mail = MailMessage::Load(dataDir + u"tnefWithMsgInside.eml", [&]{ auto tmp_0 = System::MakeObject<EmlLoadOptions>(); tmp_0->set_PreserveEmbeddedMessageFormat(true); return tmp_0; }());
    
    FileFormatType fileFormat = FileFormatUtil::DetectFileFormat(mail->get_Attachments()->idx_get(0)->get_ContentStream())->get_FileFormatType();
    
    System::Console::WriteLine(System::String(u"Embedded message file format: ") + System::ObjectExt::ToString(fileFormat));
    //ExEnd: PreserveEmbeddedMSGFormatDuringLoad
}






