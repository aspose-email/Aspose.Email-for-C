/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerable.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageAddedEventArgs.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

static void OnMessageAdded(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::MessageAddedEventArgs> e)
{
    System::Console::WriteLine(e->get_EntryId());
    System::Console::WriteLine(e->get_Message()->get_Subject());
}


void BulkAddFromAnotherPst(System::String source)
{
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(source, false);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ pst});
        // ------------------------------------------
        
        try{
            System::SharedPtr<PersonalStorage> pstDest = PersonalStorage::FromFile(GetDataDir_Outlook() + u"PersonalStorageFile1.pst");
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ pstDest});
            // ------------------------------------------
            
            try
            {
                // Get the folder by name
                System::SharedPtr<FolderInfo> folderInfo = pst->get_RootFolder()->GetSubFolder(u"Contacts");
                System::SharedPtr<MessageInfoCollection> ms = folderInfo->GetContents();
                
                // Get the folder by name
                System::SharedPtr<FolderInfo> f = pstDest->get_RootFolder()->GetSubFolder(u"myInbox");
                f->MessageAdded.connect(OnMessageAdded);
                f->AddMessages(folderInfo->EnumerateMapiMessages());
                System::SharedPtr<FolderInfo> fi = pstDest->get_RootFolder()->GetSubFolder(u"myInbox");
                System::SharedPtr<MessageInfoCollection> msgs = fi->GetContents();
                
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    
}


void AddMessagesFromOtherPST()
{
    System::String dataDir = GetDataDir_Outlook();

    // Load the Outlook file
    System::String path = dataDir + u"SampleContacts.pst";
    BulkAddFromAnotherPst(path);
}
