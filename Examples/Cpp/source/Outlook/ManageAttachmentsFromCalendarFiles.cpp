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
#include <system/io/memory_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Calendar/AppointmentSaveFormat.h>
#include <Calendar/Appointment.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;

void ManageAttachmentsFromCalendarFiles()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:GetAttachmentsFromCalendar 
    System::ArrayPtr<System::String> files = System::MakeArray<System::String>(3);
    files[0] = dataDir + u"attachment_1.doc";
    files[1] = dataDir + u"download.png";
    files[2] = dataDir + u"Desert.jpg";
    
    System::SharedPtr<Appointment> app1 = System::MakeObject<Appointment>(u"Home", System::DateTime::get_Now().AddHours(1), System::DateTime::get_Now().AddHours(1), MailAddress::to_MailAddress(u"organizer@domain.com"), MailAddressCollection::to_MailAddressCollection(u"attendee@gmail.com"));
    
    {
        for (int i_ = 0; i_ < files->Count(); ++i_)
        {
            System::String file = files[i_];
            {
                {
                    System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>(System::IO::File::ReadAllBytes(file));
                    // Clearing resources under 'using' statement
                    System::Details::DisposeGuard<1> __dispose_guard_0({ ms});
                    // ------------------------------------------
                    
                    try
                    {
                        app1->get_Attachments()->Add(System::MakeObject<Attachment>(ms, System::IO::Path::GetFileName(file)));
                    }
                    catch(...)
                    {
                        __dispose_guard_0.SetCurrentException(std::current_exception());
                    }
                }
            }
        }
    }
    
    app1->Save(dataDir + u"appWithAttachments_out.ics", Aspose::Email::Calendar::AppointmentSaveFormat::Ics);
    
    System::SharedPtr<Appointment> app2 = Appointment::Load(dataDir + u"appWithAttachments_out.ics");
    System::Console::WriteLine(app2->get_Attachments()->get_Count());
    
    {
        auto att_enumerator = (app2->get_Attachments())->GetEnumerator();
        decltype(att_enumerator->get_Current()) att;
        while (att_enumerator->MoveNext() && (att = att_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(att->get_Name());
        }
    }
    // ExEnd:GetAttachmentsFromCalendar
}

