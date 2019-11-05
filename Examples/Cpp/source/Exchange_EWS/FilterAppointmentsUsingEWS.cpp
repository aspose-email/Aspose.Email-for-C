#include "Examples.h"
#include <Tools/Search/MailQuery.h>
#include <Tools/Search/DateComparisonField.h>
#include <Tools/Search/BoolComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/array.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/Search/ExchangeQueryBuilder.h>
#include <Clients/Exchange/Search/AppointmentQueryBuilder.h>
#include <Calendar/Appointment.h>


using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Exchange;
using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Tools::Search;
void FilterAppointmentsUsingEWS()
{
    // Connect to EWS
    const System::String mailboxUri = u"https://outlook.office365.com/ews/exchange.asmx";
    const System::String username = u"username";
    const System::String password = u"password";
    const System::String domain = u"domain";
    
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());
    
    System::DateTime startTime(2017, 9, 15);
    System::DateTime endTime(2017, 10, 10);
    System::SharedPtr<ExchangeQueryBuilder> builder = System::MakeObject<ExchangeQueryBuilder>();
    builder->get_Appointment()->get_Start()->Since(startTime);
    builder->get_Appointment()->get_End()->BeforeOrEqual(endTime);
    System::SharedPtr<MailQuery> query = builder->GetQuery();
    System::ArrayPtr<System::SharedPtr<Appointment>> appointments = client->ListAppointments(query);
    
    builder = System::MakeObject<ExchangeQueryBuilder>();
    builder->get_Appointment()->get_IsRecurring()->Equals(false);
    query = builder->GetQuery();
    appointments = client->ListAppointments(query);
}
