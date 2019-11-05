#include "Examples.h"
#include <system/enumerator_adapter.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/dictionary.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/AppointmentPageInfo.h>
#include <Calendar/AppointmentCollection.h>
#include <Calendar/Appointment.h>


using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Exchange;

void PagingSupportForListingAppointments()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    try
    {
        System::ArrayPtr<System::SharedPtr<Appointment>> appts = client->ListAppointments();
        System::Console::WriteLine(appts->get_Length());
        System::DateTime date = System::DateTime::get_Now();
        System::DateTime startTime(date.get_Year(), date.get_Month(), date.get_Day(), date.get_Hour(), 0, 0);
        System::DateTime endTime = startTime.AddHours(1);
        int32_t appNumber = 10;
        System::SharedPtr<System::Collections::Generic::Dictionary<System::String, System::SharedPtr<Appointment>>> appointmentsDict = System::MakeObject<System::Collections::Generic::Dictionary<System::String, System::SharedPtr<Appointment>>>();
        for (int32_t i = 0; i < appNumber; i++)
        {
            startTime = startTime.AddHours(1);
            endTime = endTime.AddHours(1);
            System::String timeZone = u"America/New_York";
            System::SharedPtr<Appointment> appointment = System::MakeObject<Appointment>(u"Room 112", startTime, endTime, MailAddress::to_MailAddress(u"from@domain.com"), MailAddressCollection::to_MailAddressCollection(u"to@domain.com"));
            appointment->SetTimeZone(timeZone);
            appointment->set_Summary(System::String(u"NETWORKNET-35157_3 - ") + System::ObjectExt::ToString(System::Guid::NewGuid()));
            appointment->set_Description(u"EMAILNET-35157 Move paging parameters to separate class");
            System::String uid = client->CreateAppointment(appointment);
            appointmentsDict->Add(uid, appointment);
        }
        System::SharedPtr<AppointmentCollection> totalAppointmentCol = AppointmentCollection::to_AppointmentCollection(client->ListAppointments());

        /// // LISTING APPOINTMENTS WITH PAGING SUPPORT ///////
        int32_t itemsPerPage = 2;
        System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<AppointmentPageInfo>>> pages = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<AppointmentPageInfo>>>();
        System::SharedPtr<AppointmentPageInfo> pagedAppointmentCol = client->ListAppointmentsByPage(itemsPerPage);
        System::Console::WriteLine(pagedAppointmentCol->get_Items()->get_Count());
        pages->Add(pagedAppointmentCol);
        while (!pagedAppointmentCol->get_LastPage())
        {
            pagedAppointmentCol = client->ListAppointmentsByPage(itemsPerPage, pagedAppointmentCol->get_PageOffset() + 1);
            pages->Add(pagedAppointmentCol);
        }
        int32_t retrievedItems = 0;
        for (auto folderCol : System::IterateOver(pages))
        {
            retrievedItems += folderCol->get_Items()->get_Count();
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

}