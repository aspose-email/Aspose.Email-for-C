//using System.Collections;
/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerable.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageAddedEventHandler.h>
#include <Formats/Outlook/Pst/Messaging/MessageAddedEventArgs.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;

void OnMessageAdded(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Outlook::Pst::MessageAddedEventArgs> e)
{
    System::Console::WriteLine(e->get_EntryId());
    System::Console::WriteLine(e->get_Message()->get_Subject());
}


void BulkAddFromAnotherPst(System::String source)
{
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(source, false);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        {
            System::SharedPtr<PersonalStorage> pstDest = PersonalStorage::FromFile(GetDataDir_Outlook() + L"PersonalStorageFile1.pst");
            
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard __dispose_guard_1{ pstDest, ASPOSE_CURRENT_FUNCTION_LINE };
            // ------------------------------------------
            // Get the folder by name
            System::SharedPtr<FolderInfo> folderInfo = pst->get_RootFolder()->GetSubFolder(L"Contacts");
            System::SharedPtr<MessageInfoCollection> ms = folderInfo->GetContents();
            
            // Get the folder by name
            System::SharedPtr<FolderInfo> f = pstDest->get_RootFolder()->GetSubFolder(L"myInbox");
            f->MessageAdded.connect(OnMessageAdded);
            f->AddMessages(folderInfo->EnumerateMapiMessages());
            System::SharedPtr<FolderInfo> fi = pstDest->get_RootFolder()->GetSubFolder(L"myInbox");
            System::SharedPtr<MessageInfoCollection> msgs = fi->GetContents();
            
        }
    }
    
}

void AddMessagesFromOtherPST()
{
    System::String dataDir = GetDataDir_Outlook();

    // Load the Outlook file
    System::String path = dataDir + L"SampleContacts.pst";
    BulkAddFromAnotherPst(path);
}




