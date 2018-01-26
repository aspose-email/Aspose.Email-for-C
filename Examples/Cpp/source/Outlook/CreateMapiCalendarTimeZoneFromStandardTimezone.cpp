//using Aspose.Email.Outlook;
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/timezone_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiCalendarTimeZone.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>
#include <Formats/Outlook/IMapiMessageItem.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void CreateMapiCalendarTimeZoneFromStandardTimezone()
{
    System::String dataDir = GetDataDir_Outlook();
    System::String fileName = dataDir + L"Test Meeting.msg";
    
    System::SharedPtr<MapiMessage> message = MapiMessage::FromFile(fileName);
    System::SharedPtr<MapiCalendar> calendar = System::DynamicCast<Aspose::Email::Outlook::MapiCalendar>(message->ToMapiMessageItem());
    
    // ExStart:CreateMapiCalendarTimeZoneFromStandardTimezone
    System::SharedPtr<MapiCalendarTimeZone> timeZone = System::MakeObject<MapiCalendarTimeZone>(System::TimeZoneInfo::get_Local());
    // ExEnd:CreateMapiCalendarTimeZoneFromStandardTimezone
    
    calendar->set_StartDateTimeZone(timeZone);
    calendar->set_EndDateTimeZone(timeZone);
}







