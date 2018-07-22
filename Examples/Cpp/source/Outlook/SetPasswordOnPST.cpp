/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageStore.h>
#include <Storage/Pst/FileFormatVersion.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void SetPasswordOnPST()
{
    // The path to the File directory.
    // ExStart:SetPasswordOnPST
    System::String dataDir = GetDataDir_Outlook();
    
    System::String alreadyCreated = dataDir + u"SetPasswordOnPST_out.pst";
    if (System::IO::File::Exists(alreadyCreated))
    {
        System::IO::File::Delete(alreadyCreated);
    }
    else { }
    
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dataDir + u"SetPasswordOnPST_out.pst", Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ pst});
        // ------------------------------------------
        
        try
        {
            // Set the password
            const System::String password = u"Password1";
            pst->get_Store()->ChangePassword(password);
            // Remove the password
            pst->get_Store()->ChangePassword(nullptr);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:SetPasswordOnPST
}

