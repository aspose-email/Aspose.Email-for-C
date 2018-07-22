/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <MailMessage.h>
#include <LinkedResourceCollection.h>
#include <AlternateViewCollection.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email;

void RemoveLRTracesFromMessageBody()
{
    // ExStart:RemoveLRTracesFromMessageBody
    System::String dataDir = GetDataDir_Email();
    
    //sample input file
    System::String fileName = u"EmlWithLinkedResources.eml";
    
    //Load the test message with Linked Resources
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + fileName);
    
    //Remove a LinkedResource
    msg->get_LinkedResources()->RemoveAt(0, true);
    
    //Now clear the Alternate View for linked Resources
    msg->get_AlternateViews()->idx_get(0)->get_LinkedResources()->Clear(true);
    // ExEnd:RemoveLRTracesFromMessageBody
}






