/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/FileFormatUtil.h>
#include <Tools/FileFormatType.h>
#include <Tools/FileFormatInfo.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Tools;

void DetectDifferentFileFormats()
{
    // ExStart:DetectDifferentFileFormats
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Detect file format and Gets the detected load format
    System::SharedPtr<FileFormatInfo> info = FileFormatUtil::DetectFileFormat(dataDir + u"message.msg");
    System::Console::WriteLine(System::String(u"The message format is: ") + System::ObjectExt::ToString(info->get_FileFormatType()));
    // ExEnd:DetectDifferentFileFormats
}






