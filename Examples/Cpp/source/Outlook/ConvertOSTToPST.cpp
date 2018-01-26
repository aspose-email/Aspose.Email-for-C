/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/FileFormat.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void ConvertOSTToPST()
{
    // ExStart:ConvertOSTToPST
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + L"PersonalStorage.pst";
    
    // Get the Display Name of the file
    {
        System::SharedPtr<PersonalStorage> ost = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ ost, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        ost->SaveAs(dataDir + L"ConvertOSTToPST_out.pst", Aspose::Email::Outlook::Pst::FileFormat::Pst);
    }
    // ExEnd:ConvertOSTToPST
}







