/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/collections/list.h>
#include <system/collections/ilist.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void DeleteBulkItemsFromPSTFile()
{
    // ExStart:DeleteBulkItemsFromPSTFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook() + u"Sub.pst";
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dataDir);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            // Get Inbox SubFolder from Outlook file
            System::SharedPtr<FolderInfo> inbox = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
            
            // Create instance of PersonalStorageQueryBuilder
            System::SharedPtr<PersonalStorageQueryBuilder> queryBuilder = System::MakeObject<PersonalStorageQueryBuilder>();
            
            queryBuilder->get_From()->Contains(u"someuser@domain.com");
            System::SharedPtr<MessageInfoCollection> messages = inbox->GetContents(queryBuilder->GetQuery());
            System::SharedPtr<System::Collections::Generic::IList<System::String>> deleteList = System::MakeObject<System::Collections::Generic::List<System::String>>();
            
            {
                auto messageInfo_enumerator = (messages)->GetEnumerator();
                decltype(messageInfo_enumerator->get_Current()) messageInfo;
                while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
                {
                    deleteList->Add(messageInfo->get_EntryIdString());
                }
            }
            
            // delete messages having From = "someuser@domain.com"
            inbox->DeleteChildItems(deleteList);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:DeleteBulkItemsFromPSTFile
}

