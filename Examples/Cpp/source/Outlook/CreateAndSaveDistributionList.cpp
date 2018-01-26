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
#include <Formats/Outlook/Mapi/MapiDistributionListMemberCollection.h>
#include <Formats/Outlook/Mapi/MapiDistributionListMember.h>
#include <Formats/Outlook/Mapi/MapiDistributionList.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void CreateAndSaveDistributionList()
{
    // ExStart:CreateAndSaveDistributionList
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Create MapiDistributionListMemberCollection object and add MapiDistributionListMembers
    System::SharedPtr<MapiDistributionListMemberCollection> oneOffmembers = System::MakeObject<MapiDistributionListMemberCollection>();
    oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(L"John R. Patrick", L"JohnRPatrick@armyspy.com"));
    oneOffmembers->Add(System::MakeObject<MapiDistributionListMember>(L"Tilly Bates", L"TillyBates@armyspy.com"));
    
    System::SharedPtr<MapiDistributionList> dlist = System::MakeObject<MapiDistributionList>(L"Simple list", oneOffmembers);
    // Set MapiDistributionList properties
    dlist->set_Body(L"Test body");
    dlist->set_Subject(L"Test subject");
    dlist->set_Mileage(L"Test mileage");
    dlist->set_Billing(L"Test billing");
    
    dlist->Save(dataDir + L"distlist_out.msg");
    // ExEnd:CreateAndSaveDistributionList
}







