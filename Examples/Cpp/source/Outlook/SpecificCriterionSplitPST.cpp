/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/MailQuery.h>
#include <Tools/Search/DateComparisonField.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file.h>
#include <system/io/directory.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/collections/list.h>
#include <system/collections/ilist.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;
using namespace Aspose::Email::Tools::Search;

void SpecificCriterionSplitPST()
{
    // The path to the File directory.
    // ExStart:SpecificCriterionSplitPST
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<System::Collections::Generic::IList<System::SharedPtr<MailQuery>>> criteria = System::MakeObject<System::Collections::Generic::List<System::SharedPtr<MailQuery>>>();
    System::SharedPtr<PersonalStorageQueryBuilder> pstQueryBuilder = System::MakeObject<PersonalStorageQueryBuilder>();
    pstQueryBuilder->get_SentDate()->Since(System::DateTime(2005, 4, 1));
    pstQueryBuilder->get_SentDate()->Before(System::DateTime(2005, 4, 7));
    criteria->Add(pstQueryBuilder->GetQuery());
    pstQueryBuilder = System::MakeObject<PersonalStorageQueryBuilder>();
    pstQueryBuilder->get_SentDate()->Since(System::DateTime(2005, 4, 7));
    pstQueryBuilder->get_SentDate()->Before(System::DateTime(2005, 4, 13));
    criteria->Add(pstQueryBuilder->GetQuery());
    
    if (System::IO::Directory::GetFiles(dataDir + u"pathToPst", u"*.pst")->get_Length() == 0) { }
    else
    {
        System::ArrayPtr<System::String> files = System::IO::Directory::GetFiles(dataDir + u"pathToPst");
        
        
        {
            for (int i_ = 0; i_ < files->Count(); ++i_)
            {
                System::String file = files[i_];
                {
                    if (file.Contains(u".pst"))
                    {
                        System::IO::File::Delete(file);
                    }
                }
            }
        }
    }
    
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir + u"PersonalStorage_New.pst");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            personalStorage->SplitInto(criteria, dataDir + u"pathToPst");
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:SpecificCriterionSplitPST
}

