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
#include <Mapi/MapiDistributionListMemberCollection.h>
#include <Mapi/MapiDistributionListMember.h>
#include <Mapi/MapiDistributionList.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void CreateAndSaveDistributionList()
{
    // ExStart:CreateAndSaveDistributionList
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create MapiDistributionListMemberCollection object and add MapiDistributionListMembers
    System::SharedPtr<MapiDistributionListMemberCollection> oneOffmembers = System::MakeObject<MapiDistributionListMemberCollection>();
    oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(u"John R. Patrick", u"JohnRPatrick@armyspy.com"));
    oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(u"Tilly Bates", u"TillyBates@armyspy.com"));
    
    System::SharedPtr<MapiDistributionList> dlist = System::MakeObject<MapiDistributionList>(u"Simple list", oneOffmembers);
    // Set MapiDistributionList properties
    dlist->set_Body(u"Test body");
    dlist->set_Subject(u"Test subject");
    dlist->set_Mileage(u"Test mileage");
    dlist->set_Billing(u"Test billing");
    
    dlist->Save(dataDir + u"distlist_out.msg");
    // ExEnd:CreateAndSaveDistributionList
}

