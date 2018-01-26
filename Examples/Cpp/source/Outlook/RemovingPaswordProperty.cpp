/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/bit_converter.h>
#include <system/array.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageStore.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void RemovingPaswordProperty()
{
    // The path to the File directory.
    // ExStart:RemovingPaswordProperty
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + L"PersonalStorage1.pst");
    if (personalStorage->get_Store()->get_Properties()->Contains(MapiPropertyTag::PR_PST_PASSWORD))
    {
        System::SharedPtr<MapiProperty> property = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_PST_PASSWORD, System::BitConverter::GetBytes((int64_t)0));
        personalStorage->get_Store()->SetProperty(property);
    }
    // ExEnd:RemovingPaswordProperty
}







