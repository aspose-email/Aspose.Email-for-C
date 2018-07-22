/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FileFormat.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void ConvertOSTToPST()
{
    // ExStart:ConvertOSTToPST
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorage.pst";
    
    // Get the Display Name of the file
    {
        System::SharedPtr<PersonalStorage> ost = PersonalStorage::FromFile(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ ost});
        // ------------------------------------------
        
        try
        {
            ost->SaveAs(dataDir + u"ConvertOSTToPST_out.pst", Aspose::Email::Storage::Pst::FileFormat::Pst);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:ConvertOSTToPST
}

