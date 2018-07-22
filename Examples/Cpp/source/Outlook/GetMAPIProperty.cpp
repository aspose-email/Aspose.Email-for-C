/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void GetMAPIProperty()
{
    // ExStart:GetMAPIProperty
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load from file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + u"message.msg");
    
    System::String subject;
    
    // Access the MapiPropertyTag.PR_SUBJECT property
    System::SharedPtr<MapiProperty> prop = msg->get_Properties()->idx_get(MapiPropertyTag::PR_SUBJECT);
    
    // If the property is not found, check the MapiPropertyTag.PR_SUBJECT_W (which is a // Unicode peer of the MapiPropertyTag.PR_SUBJECT)
    if (prop == nullptr)
    {
        prop = msg->get_Properties()->idx_get(MapiPropertyTag::PR_SUBJECT_W);
    }
    
    // Cannot found
    if (prop == nullptr)
    {
        System::Console::WriteLine(u"No property found!");
        return;
    }
    
    // Get the property data as string
    subject = prop->GetString();
    
    System::Console::WriteLine(System::String(u"Subject:") + subject);
    // Read internet code page property
    prop = msg->get_Properties()->idx_get(MapiPropertyTag::PR_INTERNET_CPID);
    if (prop != nullptr)
    {
        System::Console::WriteLine(System::String(u"CodePage:") + prop->GetLong());
    }
    // ExEnd:GetMAPIProperty
}

