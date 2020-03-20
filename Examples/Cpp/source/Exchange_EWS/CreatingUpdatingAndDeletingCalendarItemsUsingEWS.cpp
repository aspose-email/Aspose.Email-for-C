#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/array.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Calendar/Appointment.h>

using namespace System;
using namespace Aspose::Email;
using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Exchange::WebService;

void CreatingUpdatingAndDeletingCalendarItemsUsingEWS()
{
    try
    {
        System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
        System::DateTime date = System::DateTime::get_Now();
        System::DateTime startTime(date.get_Year(), date.get_Month(), date.get_Day(), date.get_Hour(), 0, 0);
        System::DateTime endTime = startTime.AddHours(1);
        System::String timeZone = u"America/New_York";
        
        System::SharedPtr<Appointment> app = System::MakeObject<Appointment>(u"Room 112", startTime, endTime, MailAddress::to_MailAddress(u"organizeraspose-email.test3@domain.com"), MailAddressCollection::to_MailAddressCollection(u"attendee@gmail.com"));
        app->SetTimeZone(timeZone);
        app->set_Summary(System::String(u"NETWORKNET-34136") + System::ObjectExt::ToString(System::Guid::NewGuid()));
        app->set_Description(u"NETWORKNET-34136 Exchange 2007/EWS: Provide support for Add/Update/Delete calendar items");
        
        System::String uid = client->CreateAppointment(app);
        System::SharedPtr<Appointment> fetchedAppointment1 = client->FetchAppointment(uid);
        app->set_Location(u"Room 115");
        app->set_Summary(System::String(u"New summary for ") + app->get_Summary());
        app->set_Description(u"New Description");
        client->UpdateAppointment(app);
        
        System::ArrayPtr<System::SharedPtr<Appointment>> appointments1 = client->ListAppointments();
        System::Console::WriteLine(System::String(u"Total Appointments: ") + appointments1->get_Length());
        System::SharedPtr<Appointment> fetchedAppointment2 = client->FetchAppointment(uid);
        System::Console::WriteLine(System::String(u"Summary: ") + fetchedAppointment2->get_Summary());
        System::Console::WriteLine(System::String(u"Location: ") + fetchedAppointment2->get_Location());
        System::Console::WriteLine(System::String(u"Description: ") + fetchedAppointment2->get_Description());
        client->CancelAppointment(app);
        System::ArrayPtr<System::SharedPtr<Appointment>> appointments2 = client->ListAppointments();
        System::Console::WriteLine(System::String(u"Total Appointments: ") + appointments2->get_Length());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
