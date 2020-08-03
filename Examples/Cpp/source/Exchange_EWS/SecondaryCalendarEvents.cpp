#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>
#include <Calendar/Appointment.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Exchange;
void SecondaryCalendarEvents()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    // Clearing resources under 'using' statement

    try
    {

        System::DateTime date = System::DateTime::get_Now();
        System::DateTime startTime(date.get_Year(), date.get_Month(), date.get_Day(), date.get_Hour(), 0, 0);
        System::DateTime endTime = startTime.AddHours(1);

        System::String timeZone = u"America/New_York";

        System::ArrayPtr<System::SharedPtr<Appointment>> listAppointments;
        System::SharedPtr<Appointment> appointment = System::MakeObject<Appointment>(u"Room 121", startTime, endTime, MailAddress::to_MailAddress(u"from@domain.com"), MailAddressCollection::to_MailAddressCollection(u"attendee@domain.com"));
        appointment->SetTimeZone(timeZone);
        appointment->set_Summary(System::String(u"EMAILNET-35198 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
        appointment->set_Description(u"EMAILNET-35198 Ability to add event to Secondary Calendar of Office 365");

        // Verify that the new folder has been created
        System::SharedPtr<ExchangeFolderInfoCollection> calendarSubFolders = client->ListSubFolders(client->get_MailboxInfo()->get_CalendarUri());

        System::String getfolderName;
        System::String setFolderName = u"New Calendar";
        bool alreadyExits = false;

        // Verify that the new folder has been created already exits or not 

        for (int32_t i = 0; i < calendarSubFolders->get_Count(); i++)
        {
            getfolderName = calendarSubFolders->idx_get(i)->get_DisplayName();

            if (System::ObjectExt::Equals(getfolderName, setFolderName))
            {
                alreadyExits = true;
            }
        }

        if (alreadyExits)
        {
            System::Console::WriteLine(u"Folder Already Exists");
        }
        else
        {
            // Create new calendar folder
            client->CreateFolder(client->get_MailboxInfo()->get_CalendarUri(), setFolderName, nullptr, u"IPF.Appointment");

            System::Console::WriteLine(calendarSubFolders->get_Count());

            // Get the created folder URI
            System::String newCalendarFolderUri = calendarSubFolders->idx_get(0)->get_Uri();

            // appointment api with calendar folder uri
            // Create
            client->CreateAppointment(appointment, newCalendarFolderUri);
            appointment->set_Location(u"Room 122");
            // update
            client->UpdateAppointment(appointment, newCalendarFolderUri);
            // list
            listAppointments = client->ListAppointments(newCalendarFolderUri);

            // list default calendar folder
            listAppointments = client->ListAppointments(client->get_MailboxInfo()->get_CalendarUri());

            // Cancel
            client->CancelAppointment(appointment, newCalendarFolderUri);
            listAppointments = client->ListAppointments(newCalendarFolderUri);

            // appointment api with context current calendar folder uri
            client->set_CurrentCalendarFolderUri(newCalendarFolderUri);
            // Create
            client->CreateAppointment(appointment);
            appointment->set_Location(u"Room 122");
            // update
            client->UpdateAppointment(appointment);
            // list
            listAppointments = client->ListAppointments();

            // list default calendar folder
            listAppointments = client->ListAppointments(client->get_MailboxInfo()->get_CalendarUri());

            // Cancel
            client->CancelAppointment(appointment);
            listAppointments = client->ListAppointments();

        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
}