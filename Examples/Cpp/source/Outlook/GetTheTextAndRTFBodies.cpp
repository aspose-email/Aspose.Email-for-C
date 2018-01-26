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
#include <system/console.h>
#include <Formats/Outlook/Mapi/MapiMessageItemBase.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void GetTheTextAndRTFBodies()
{
    // ExStart:GetTheTextAndRTFBodies
    System::String dataDir = GetDataDir_Outlook();
    
    // Load mail message
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromMailMessage(dataDir + L"Message.eml");
    
    System::SharedPtr<MapiMessageItemBase> itemBase = System::MakeObject<MapiMessage>();
    // Text body
    if (itemBase->get_Body() != nullptr)
    {
        System::Console::WriteLine(msg->get_Body());
    }
    else
    {
        System::Console::WriteLine(L"There's no text body.");
    }
    
    // RTF body
    if (itemBase->get_BodyRtf() != nullptr)
    {
        System::Console::WriteLine(msg->get_BodyRtf());
    }
    else
    {
        System::Console::WriteLine(L"There's no RTF body.");
    }
    // ExEnd:GetTheTextAndRTFBodies
}







