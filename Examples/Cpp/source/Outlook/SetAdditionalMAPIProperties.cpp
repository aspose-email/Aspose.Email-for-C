/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/guid.h>
#include <system/exceptions.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/collections/list.h>
#include <system/collections/ilist.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Mapi/MapiPropertyType.h>
#include <Mapi/MapiPropertyContainer.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiNamedPropertyMappingStorage.h>
#include <Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void SetAdditionalMAPIProperties()
{
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + u"message.msg");
    
    // ExStart:SetAdditionalMAPIProperties
    // PT_MV_FLOAT, PT_MV_R4, mv.float
    System::SharedPtr<System::Collections::Generic::IList<System::SharedPtr<System::Object>>> values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<float>((float)1));
    values->Add(System::ObjectExt::Box<float>((float)2));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901004, values));
    
    // PT_MV_DOUBLE, PT_MV_R8
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<double>((double)1));
    values->Add(System::ObjectExt::Box<double>((double)2));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901005, values));
    
    // PT_MV_CURRENCY, mv.fixed.14.4
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<System::Decimal>(System::Decimal(123.34)));
    values->Add(System::ObjectExt::Box<System::Decimal>(System::Decimal(289.45)));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901006, values));
    
    // PT_MV_APPTIME
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<double>(30456.34));
    values->Add(System::ObjectExt::Box<double>(40655.45));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901007, values));
    
    // PT_MV_I8, PT_MV_LONGLONG
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<int64_t>((int64_t)30456));
    values->Add(System::ObjectExt::Box<int64_t>((int64_t)40655));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901014, values));
    
    // PT_MV_CLSID, mv.uuid
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<System::Guid>(System::Guid::NewGuid()));
    values->Add(System::ObjectExt::Box<System::Guid>(System::Guid::NewGuid()));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901048, values));
    
    // PT_MV_SHORT, PT_MV_I2, mv.i2
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<int16_t>((int16_t)1));
    values->Add(System::ObjectExt::Box<int16_t>((int16_t)2));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901002, values));
    
    // PT_MV_SYSTIME
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<System::DateTime>(System::DateTime::get_Now()));
    values->Add(System::ObjectExt::Box<System::DateTime>(System::DateTime::get_Now()));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901040, values));
    
    // PT_MV_BOOLEAN
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<bool>(true));
    values->Add(System::ObjectExt::Box<bool>(false));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x2390100b, values));
    
    // PT_MV_BINARY
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::Guid::NewGuid().ToByteArray());
    values->Add(System::MakeArray<uint8_t>({1, 2, 4, 5, 6, 7, 5, 4, 3, 5, 6, 7, 8, 6, 4, 3, 4, 5, 6, 7, 8, 6, 5, 4, 3, 7, 8, 9, 0, 2, 3, 4}));
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x23901102, values));
    
    // PT_NULL
    System::Cast<MapiPropertyContainer>(msg)->SetProperty(System::MakeObject<MapiProperty>(0x67400001, System::MakeArray<uint8_t>(1, 0)));
    System::SharedPtr<MapiMessage> message = System::MakeObject<MapiMessage>(u"sender@test.com", u"recipient@test.com", u"subj", u"Body of test msg");
    
    // PT_MV_LONG
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<int32_t>((int32_t)4));
    System::SharedPtr<MapiProperty> property = System::MakeObject<MapiProperty>(message->get_NamedPropertyMapping()->GetNextAvailablePropertyId(Aspose::Email::Mapi::MapiPropertyType::PT_MV_LONG), values);
    message->get_NamedPropertyMapping()->AddNamedPropertyMapping(property, 0x00008028, System::Guid(u"00062004-0000-0000-C000-000000000046"));
    System::Cast<MapiPropertyContainer>(message)->SetProperty(property);
    
    // OR you can set the custom property (with the custom name)
    message = System::MakeObject<MapiMessage>(u"sender@test.com", u"recipient@test.com", u"subj", u"Body of test msg");
    values = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<System::Object>>>();
    values->Add(System::ObjectExt::Box<int32_t>((int32_t)4));
    property = System::MakeObject<MapiProperty>(message->get_NamedPropertyMapping()->GetNextAvailablePropertyId(Aspose::Email::Mapi::MapiPropertyType::PT_MV_LONG), values);
    message->AddCustomProperty(property, u"customProperty");
    
    //PT_FLOAT
    //Please note that you need explicit cast to float value for this to work
    float floatValue = (float)123.456;
    System::SharedPtr<MapiMessage> newMsg = System::MakeObject<MapiMessage>();
    int64_t floatTag = newMsg->get_NamedPropertyMapping()->GetNextAvailablePropertyId(Aspose::Email::Mapi::MapiPropertyType::PT_FLOAT);
    System::Guid guid = System::Guid::NewGuid();
    System::SharedPtr<MapiProperty> newMapiProperty = System::MakeObject<MapiProperty>(floatTag, System::BitConverter::GetBytes(floatValue));
    newMsg->get_NamedPropertyMapping()->AddNamedPropertyMapping(newMapiProperty, 12, guid);
    System::Cast<MapiPropertyContainer>(newMsg)->SetProperty(newMapiProperty);
    
    // ExEnd:SetAdditionalMAPIProperties
}

