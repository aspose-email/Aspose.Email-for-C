/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageStore.h>
#include <Mapi/MapiPropertyTag.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

bool IsPasswordProtected(System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst)
{
    // If the property exists and is nonzero, then the PST file is password protected.
    if (pst->get_Store()->get_Properties()->ContainsKey(MapiPropertyTag::PR_PST_PASSWORD))
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
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(dataDir + u"passwordprotectedPST.pst");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ pst});
        // ------------------------------------------
        
        try
        {
            System::Console::WriteLine(u"PST is protected: {0}", System::ObjectExt::Box<bool>(IsPasswordProtected(pst)));
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
}


