/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormat.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void DisplayFolderContents(System::SharedPtr<Aspose::Email::Storage::Pst::FolderInfo> folderInfo, System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst)
{
    // Display the folder name
    System::Console::WriteLine(System::String(u"Folder: ") + folderInfo->get_DisplayName());
    System::Console::WriteLine(u"==================================");
    // Display information about messages inside this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();

    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(u"Subject: ") + messageInfo->get_Subject());
            System::Console::WriteLine(System::String(u"Sender: ") + messageInfo->get_SenderRepresentativeName());
            System::Console::WriteLine(System::String(u"Recipients: ") + messageInfo->get_DisplayTo());
            System::Console::WriteLine(u"------------------------------");
        }
    }

    // Call this method recursively for each subfolder
    if (folderInfo->get_HasSubFolders() == true)
    {
        auto subfolderInfo_enumerator = (folderInfo->GetSubFolders())->GetEnumerator();
        decltype(subfolderInfo_enumerator->get_Current()) subfolderInfo;
        while (subfolderInfo_enumerator->MoveNext() && (subfolderInfo = subfolderInfo_enumerator->get_Current(), true))
        {
            DisplayFolderContents(subfolderInfo, pst);
        }
    }
}

void GetMessageInformation()
{
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorage.pst";
    
    try
    {
        
        // Load the Outlook PST file
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        
        // Get the Display Format of the PST file
        System::Console::WriteLine(System::String(u"Display Format: ") + System::ObjectExt::ToString(personalStorage->get_Format()));
        
        // Get the folders and messages information
        System::SharedPtr<FolderInfo> folderInfo = personalStorage->get_RootFolder();
        
        // Call the recursive method to display the folder contents
        DisplayFolderContents(folderInfo, personalStorage);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}


