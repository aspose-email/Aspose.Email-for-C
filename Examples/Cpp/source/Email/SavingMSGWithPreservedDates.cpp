/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/path.h>
#include <MsgSaveOptions.h>
#include <MailMessageSaveType.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void SavingMSGWithPreservedDates()
{
    // ExStart:SavingMSGWithPreservedDates
    // Data directory for reading and writing files
    System::String dataDir = GetDataDir_Email();
    
    // Initialize and Load an existing EML file by specifying the MessageFormat
    System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir + u"Message.eml");
    
    // Save as msg with preserved dates
    System::SharedPtr<MsgSaveOptions> msgSaveOptions = [&]{ auto tmp_0 = System::MakeObject<MsgSaveOptions>(MailMessageSaveType::get_OutlookMessageFormatUnicode()); tmp_0->set_PreserveOriginalDates(true); return tmp_0; }();
    
    eml->Save(System::IO::Path::Combine(dataDir, u"outTest_out.msg"), msgSaveOptions);
    // ExEnd:SavingMSGWithPreservedDates
}






