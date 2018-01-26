//using Aspose.Email.PersonalInfo.VCard;
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Formats/VCard/VCardContact.h>
#include <Formats/Outlook/Mapi/MapiContact.h>

#include "Examples.h"


using namespace Aspose::Email::Formats::VCard;
using namespace Aspose::Email::Outlook;


void LoadingContactFromVCard()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:LoadingContactFromVCard
    auto vcfTest = VCardContact::Load(dataDir + L"Contact.vcf");
    System::SharedPtr<MapiContact> contact = MapiContact::FromVCard(dataDir + L"Contact.vcf");
    // ExEnd:LoadingContactFromVCard
}






