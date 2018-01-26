/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from http://www.aspose.com/downloads, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using http://www.aspose.com/community/forums/default.aspx            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/FileFormat.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;

void DisplayFolderContents(System::SharedPtr<Aspose::Email::Outlook::Pst::FolderInfo> folderInfo, System::SharedPtr<Aspose::Email::Outlook::Pst::PersonalStorage> pst)
{
    // Display the folder name
    System::Console::WriteLine(System::String(L"Folder: ") + folderInfo->get_DisplayName());
    System::Console::WriteLine(L"==================================");
    // Display information about messages inside this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();

    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(L"Subject: ") + messageInfo->get_Subject());
            System::Console::WriteLine(System::String(L"Sender: ") + messageInfo->get_SenderRepresentativeName());
            System::Console::WriteLine(System::String(L"Recipients: ") + messageInfo->get_DisplayTo());
            System::Console::WriteLine(L"------------------------------");
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
    System::String path = dataDir + L"PersonalStorage.pst";
    
    try
    {
        
        // Load the Outlook PST file
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        
        // Get the Display Format of the PST file
        System::Console::WriteLine(System::String(L"Display Format: ") + System::ObjectExt::ToString(personalStorage->get_Format()));
        
        // Get the folders and messages information
        System::SharedPtr<FolderInfo> folderInfo = personalStorage->get_RootFolder();
        
        // Call the recursive method to display the folder contents
        DisplayFolderContents(folderInfo, personalStorage);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}








