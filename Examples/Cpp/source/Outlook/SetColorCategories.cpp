//using System.Collections;
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/collections/ilist.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;


void SetColorCategories()
{
    // ExStart:SetColorCategories
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"message1.msg");
    
    // Add Two category
    FollowUpManager::AddCategory(msg, L"Purple Category");
    FollowUpManager::AddCategory(msg, L"Red Category");
    
    // Retrieve the list of available categories
    System::SharedPtr<System::Collections::Generic::IList<System::String>> categories = FollowUpManager::GetCategories(msg);
    
    // Remove the specified category and then Clear all categories
    FollowUpManager::RemoveCategory(msg, L"Red Category");
    FollowUpManager::ClearCategories(msg);
    // ExEnd:SetColorCategories
}







