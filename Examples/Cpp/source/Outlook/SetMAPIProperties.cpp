/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/date_time.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiRecipient.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiMessageItemBase.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;

System::ArrayPtr<uint8_t> ConvertDateTime(System::DateTime t)
{
    int64_t filetime = t.ToFileTime();
    System::ArrayPtr<uint8_t> d = System::MakeArray<uint8_t>(8, 0);
    d[0] = (uint8_t)(filetime & 0xFF);
    d[1] = (uint8_t)((filetime & 0xFF00) >> 8);
    d[2] = (uint8_t)((filetime & 0xFF0000) >> 16);
    d[3] = (uint8_t)((filetime & 0xFF000000) >> 24);
    d[4] = (uint8_t)((filetime & 0xFF00000000) >> 32);
    d[5] = (uint8_t)((filetime & 0xFF0000000000) >> 40);
    d[6] = (uint8_t)((filetime & 0xFF000000000000) >> 48);
    d[7] = (uint8_t)(((uint64_t)filetime & 0xFF00000000000000) >> 56);
    return d;
}


void SetMAPIProperties()
{
    //ExStart:SetMAPIProperties
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create a sample Message
    System::SharedPtr<MapiMessage> mapiMsg = System::MakeObject<MapiMessage>(L"user1@gmail.com", L"user2@gmail.com", L"This is subject", L"This is body");
    
    // Set multiple properties
    System::StaticCast<MapiMessageItemBase>(mapiMsg)->SetProperty(System::MakeObject<MapiProperty>(MapiPropertyTag::PR_SENDER_ADDRTYPE_W, System::Text::Encoding::get_Unicode()->GetBytes(L"EX")));
    System::SharedPtr<MapiRecipient> recipientTo = mapiMsg->get_Recipients()->idx_get(0);
    System::SharedPtr<MapiProperty> propAddressType = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_RECEIVED_BY_ADDRTYPE_W, System::Text::Encoding::get_UTF8()->GetBytes(L"MYFAX"));
    recipientTo->SetProperty(propAddressType);
    System::String faxAddress = L"My Fax User@/FN=fax#/VN=voice#/CO=My Company/CI=Local";
    System::SharedPtr<MapiProperty> propEmailAddress = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_RECEIVED_BY_EMAIL_ADDRESS_W, System::Text::Encoding::get_UTF8()->GetBytes(faxAddress));
    recipientTo->SetProperty(propEmailAddress);
    mapiMsg->SetMessageFlags(Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_UNSENT | Aspose::Email::Outlook::MapiMessageFlags::MSGFLAG_FROMME);
    System::StaticCast<MapiMessageItemBase>(mapiMsg)->SetProperty(System::MakeObject<MapiProperty>(MapiPropertyTag::PR_RTF_IN_SYNC, System::BitConverter::GetBytes((int64_t)1)));
    
    // Set DateTime property
    System::SharedPtr<MapiProperty> modificationTime = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_LAST_MODIFICATION_TIME, ConvertDateTime(System::DateTime(2013, 9, 11)));
    System::StaticCast<MapiMessageItemBase>(mapiMsg)->SetProperty(modificationTime);
    mapiMsg->Save(dataDir + L"MapiProp_out.msg");
    //ExEnd:SetMAPIProperties
}








