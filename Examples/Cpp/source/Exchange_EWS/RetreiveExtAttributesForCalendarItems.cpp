#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/enumerator_adapter.h>
#include <system/console.h>
#include <system/collections/ilist.h>
#include <system/collections/icollection.h>
#include <system/array.h>
#include <Mapi/PropertyDescriptor.h>
#include <Mapi/PropertyDataType.h>
#include <Mapi/PidNamePropertyDescriptor.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiNamedProperty.h>
#include <Mapi/MapiCalendar.h>
#include <cstdint>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>


using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Mapi;
void RetreiveExtAttributesForCalendarItems()
{
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    try 
    {
        //Fetch all calendars from Exchange calendar's folder
        System::ArrayPtr<System::String> uriList = client->ListItems(client->get_MailboxInfo()->get_CalendarUri());
    
        //Define the Extended Attribute Property Descriptor for searching purpose
        //In this case, we have a K1 Long named property for Calendar item
        System::SharedPtr<PropertyDescriptor> propertyDescriptor = System::MakeObject<PidNamePropertyDescriptor>(u"K1", Aspose::Email::Mapi::PropertyDataType::Integer32, System::Guid(u"00020329-0000-0000-C000-000000000046"));
    
        //Fetch calendars that have the custom property
        System::SharedPtr<System::Collections::Generic::IList<System::SharedPtr<MapiCalendar>>> mapiCalendarList = client->FetchMapiCalendar(uriList, System::MakeArray<System::SharedPtr<Aspose::Email::Mapi::PropertyDescriptor>>({propertyDescriptor}));
    
        for (auto cal : System::IterateOver(mapiCalendarList))
        {
            for (auto namedProperty : System::IterateOver<MapiNamedProperty>(cal->get_NamedProperties()->get_Values()))
            {
                System::Console::WriteLine(namedProperty->get_NameId() + u" = " + namedProperty->GetInt32());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}
