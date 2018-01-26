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
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/FileFormat.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;



void ExtractMsgFiles(System::SharedPtr<Aspose::Email::Outlook::Pst::FolderInfo> folderInfo, System::SharedPtr<Aspose::Email::Outlook::Pst::PersonalStorage> pst)
{
    // display the folder name
    System::Console::WriteLine(System::String(L"Folder: ") + folderInfo->get_DisplayName());
    System::Console::WriteLine(L"==================================");
    // loop through all the messages in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();
    
    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(L"Saving message {0} ....", System::ObjectExt::Box<System::String>(messageInfo->get_Subject()));
            // get the message in MapiMessage instance
            System::SharedPtr<MapiMessage> message = pst->ExtractMessage(messageInfo);
            // save this message to disk in msg format
            message->Save(message->get_Subject().Replace(L":", L" ") + L".msg");
            // save this message to stream in msg format
            System::SharedPtr<System::IO::MemoryStream> messageStream = System::MakeObject<System::IO::MemoryStream>();
            message->Save(messageStream);
        }
    }
    
    // Call this method recursively for each subfolder
    if (folderInfo->get_HasSubFolders() == true)
    {
        auto subfolderInfo_enumerator = (folderInfo->GetSubFolders())->GetEnumerator();
        decltype(subfolderInfo_enumerator->get_Current()) subfolderInfo;
        while (subfolderInfo_enumerator->MoveNext() && (subfolderInfo = subfolderInfo_enumerator->get_Current(), true))
        {
            ExtractMsgFiles(subfolderInfo, pst);
        }
    }
}

void ExtractMessagesFromPSTFile()
{
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();

    // Load the Outlook file
    System::String path = dataDir + L"PersonalStorage.pst";

    try
    {
        // load the Outlook PST file
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);

        // get the Display Format of the PST file
        System::Console::WriteLine(System::String(L"Display Format: ") + System::ObjectExt::ToString(pst->get_Format()));

        // get the folders and messages information
        System::SharedPtr<FolderInfo> folderInfo = pst->get_RootFolder();

        // Call the recursive method to extract msg files from each folder
        ExtractMsgFiles(folderInfo, pst);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }

}






