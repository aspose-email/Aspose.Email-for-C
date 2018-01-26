/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/MessageStore.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void SetPasswordOnPST()
{
    // The path to the File directory.
    // ExStart:SetPasswordOnPST
    System::String dataDir = GetDataDir_Outlook();
    
    System::String alreadyCreated = dataDir + L"SetPasswordOnPST_out.pst";
    if (System::IO::File::Exists(alreadyCreated))
    {
        System::IO::File::Delete(alreadyCreated);
    }
    else { }
    
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dataDir + L"SetPasswordOnPST_out.pst", Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        // Set the password
        const System::String password = L"Password1";
        pst->get_Store()->ChangePassword(password);
        // Remove the password
        pst->get_Store()->ChangePassword(nullptr);
    }
    // ExEnd:SetPasswordOnPST
}







