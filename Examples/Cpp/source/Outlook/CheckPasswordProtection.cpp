/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageStore.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


bool IsPasswordProtected(System::SharedPtr<Aspose::Email::Outlook::Pst::PersonalStorage> pst)
{
    // If the property exists and is nonzero, then the PST file is password protected.
    if (pst->get_Store()->get_Properties()->Contains(MapiPropertyTag::PR_PST_PASSWORD))
    {
        int64_t passwordHash = pst->get_Store()->get_Properties()->idx_get(MapiPropertyTag::PR_PST_PASSWORD)->GetLong();
        return passwordHash != 0;
    }
    return false;
}

void CheckPasswordProtection()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(dataDir + L"passwordprotectedPST.pst");
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::Console::WriteLine(L"PST is protected: {0}", System::ObjectExt::Box<bool>(IsPasswordProtected(pst)));
    }
}








