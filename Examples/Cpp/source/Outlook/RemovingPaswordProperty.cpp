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
#include <system/bit_converter.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageStore.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void RemovingPaswordProperty()
{
    // The path to the File directory.
    // ExStart:RemovingPaswordProperty
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"PersonalStorage1.pst");
    if (personalStorage->get_Store()->get_Properties()->ContainsKey(MapiPropertyTag::PR_PST_PASSWORD))
    {
        System::SharedPtr<MapiProperty> property = System::MakeObject<MapiProperty>(MapiPropertyTag::PR_PST_PASSWORD, System::BitConverter::GetBytes((int64_t)0));
        personalStorage->get_Store()->SetProperty(property);
    }
    // ExEnd:RemovingPaswordProperty
}

