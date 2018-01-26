/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/timezone.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/date_time.h>
#include <Mail/MailMessage/SaveOptions/MhtSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Formats/Mhtml/MhtFormatOptions.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ExportEmailToMHTWithCustomTimezone()
{
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:ExportEmailToMHTWithCustomTimezone
    System::SharedPtr<MailMessage> eml = MailMessage::Load(dataDir + L"Message.eml");
    
    // Set the local time for message date.
    eml->set_TimeZoneOffset(System::TimeZone::get_CurrentTimeZone()->GetUtcOffset(System::DateTime::get_Now()));
    
    // or set custom time zone offset for message date (-0800)
    // eml.TimeZoneOffset = new TimeSpan(-8,0,0);
    
    // The dates will be rendered by local system time zone.
    System::SharedPtr<MhtSaveOptions> so = System::MakeObject<MhtSaveOptions>();
    so->set_MhtFormatOptions(Aspose::Email::Mail::MhtFormatOptions::WriteHeader);
    eml->Save(dataDir + L"ExportEmailToMHTWithCustomTimezone_out.mhtml", so);
    // ExEnd:ExportEmailToMHTWithCustomTimezone
}






