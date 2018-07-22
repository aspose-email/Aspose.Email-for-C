/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <PersonalInfo/VCard/VCardContact.h>
#include <Mapi/MapiContact.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::PersonalInfo::VCard;

void LoadingContactFromVCard()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:LoadingContactFromVCard
    auto vcfTest = VCardContact::Load(dataDir + u"Contact.vcf");
    System::SharedPtr<MapiContact> contact = MapiContact::FromVCard(dataDir + u"Contact.vcf");
    // ExEnd:LoadingContactFromVCard
}






