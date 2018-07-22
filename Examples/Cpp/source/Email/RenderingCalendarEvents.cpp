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
#include <system/enum_helpers.h>
#include <system/collections/specialized/string_dictionary.h>
#include <MhtTemplateName.h>
#include <MhtSaveOptions.h>
#include <MhtFormatOptions.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void RenderingCalendarEvents()
{
    //ExStart: RenderingCalendarEvents
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String fileName = u"Meeting with Recurring Occurrences.msg";
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + fileName);
    System::SharedPtr<MhtSaveOptions> options = System::MakeObject<MhtSaveOptions>();
    
    {
        options->set_MhtFormatOptions(Aspose::Email::MhtFormatOptions::WriteHeader | Aspose::Email::MhtFormatOptions::RenderCalendarEvent);
        
        //Format the output details if required - optional
        
        //Set the display for Start Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::Start))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::Start, u"<span class='headerLineTitle'>Start:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::Start, u"<span class='headerLineTitle'>Start:</span><span class='headerLineText'>{0}</span><br/>");
        }
        
        //Set the display for End Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::End))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::End, u"<span class='headerLineTitle'>End:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::End, u"<span class='headerLineTitle'>End:</span><span class='headerLineText'>{0}</span><br/>");
        }
        
        //Set the display for Recurrence Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::Recurrence))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::Recurrence, u"<span class='headerLineTitle'>Recurrence:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::Recurrence, u"<span class='headerLineTitle'>Recurrence:</span><span class='headerLineText'>{0}</span><br/>");
        }
        
        //Set the display for RecurrencePattern Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::RecurrencePattern))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::RecurrencePattern, u"<span class='headerLineTitle'>RecurrencePattern:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::RecurrencePattern, u"<span class='headerLineTitle'>RecurrencePattern:</span><span class='headerLineText'>{0}</span><br/>");
        }
        
        //Set the display for Organizer Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::Organizer))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::Organizer, u"<span class='headerLineTitle'>Organizer:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::Organizer, u"<span class='headerLineTitle'>Organizer:</span><span class='headerLineText'>{0}</span><br/>");
        }
        
        //Set the display for RequiredAttendees Property
        if (options->get_FormatTemplates()->ContainsKey(MhtTemplateName::RequiredAttendees))
        {
            options->get_FormatTemplates()->idx_set(MhtTemplateName::RequiredAttendees, u"<span class='headerLineTitle'>RequiredAttendees:</span><span class='headerLineText'>{0}</span><br/>");
        }
        else
        {
            options->get_FormatTemplates()->Add(MhtTemplateName::RequiredAttendees, u"<span class='headerLineTitle'>RequiredAttendees:</span><span class='headerLineText'>{0}</span><br/>");
        }
    }
     ;
    
    msg->Save(dataDir + u"Meeting with Recurring Occurrences.mhtml", options);
    //ExEnd: RenderingCalendarEvents
}






