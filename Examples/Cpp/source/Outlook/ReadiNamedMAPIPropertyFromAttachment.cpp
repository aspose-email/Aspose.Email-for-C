/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;


void ReadiNamedMAPIPropertyFromAttachment()
{
    //ExStart:ReadiNamedMAPIPropertyFromAttachment
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load from file
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"message.msg");
    
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
        System::Console::WriteLine(L"No property found!");
        return;
    }
    
    // Get the property data as string
    subject = prop->GetString();
    
    System::Console::WriteLine(System::String(L"Subject:") + subject);
    // Read internet code page property
    prop = msg->get_Properties()->idx_get(MapiPropertyTag::PR_INTERNET_CPID);
    if (prop != nullptr)
    {
        System::Console::WriteLine(System::String(L"CodePage:") + prop->GetLong());
    }
    //ExEnd:ReadiNamedMAPIPropertyFromAttachment
}







