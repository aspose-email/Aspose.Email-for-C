/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiContact.h>
#include <Formats/Outlook/IMapiMessageItem.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void LoadingContactFromMSG()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:LoadingContactFromMSG
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"Contact.msg");
    System::SharedPtr<MapiContact> mapiContact = System::DynamicCast<Aspose::Email::Outlook::MapiContact>(msg->ToMapiMessageItem());
    // ExEnd:LoadingContactFromMSG
}






