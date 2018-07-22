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
#include <system/enum_helpers.h>
#include <MhtSaveOptions.h>
#include <MhtFormatOptions.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void ConvertMHTMLWithOptionalSettings()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:ConvertMHTMLWithOptionalSettings
    System::SharedPtr<MailMessage> eml = MailMessage::Load(System::IO::Path::Combine(dataDir, u"Message.eml"));
    
    // Save as mht with header
    System::SharedPtr<MhtSaveOptions> mhtSaveOptions = [&]{ auto tmp_0 = System::MakeObject<MhtSaveOptions>(); tmp_0->set_MhtFormatOptions(Aspose::Email::MhtFormatOptions::WriteHeader | Aspose::Email::MhtFormatOptions::HideExtraPrintHeader | Aspose::Email::MhtFormatOptions::DisplayAsOutlook); tmp_0->set_CheckBodyContentEncoding(true); return tmp_0; }();
    eml->Save(System::IO::Path::Combine(dataDir, u"outMessage_out.mht"), mhtSaveOptions);
    // ExEnd:ConvertMHTMLWithOptionalSettings
    
    //ExStart: ConvertToMHTMLWithoutInlineImages
    mhtSaveOptions->set_SkipInlineImages(true);
    
    eml->Save(System::IO::Path::Combine(dataDir, u"EmlToMhtmlWithoutInlineImages_out.mht"), mhtSaveOptions);
    //ExEnd: ConvertToMHTMLWithoutInlineImages
}






