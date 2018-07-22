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
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfoCollection.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormat.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void ExtractMsgFiles(System::SharedPtr<Aspose::Email::Storage::Pst::FolderInfo> folderInfo, System::SharedPtr<Aspose::Email::Storage::Pst::PersonalStorage> pst)
{
    // display the folder name
    System::Console::WriteLine(System::String(u"Folder: ") + folderInfo->get_DisplayName());
    System::Console::WriteLine(u"==================================");
    // loop through all the messages in this folder
    System::SharedPtr<MessageInfoCollection> messageInfoCollection = folderInfo->GetContents();

    {
        auto messageInfo_enumerator = (messageInfoCollection)->GetEnumerator();
        decltype(messageInfo_enumerator->get_Current()) messageInfo;
        while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(u"Saving message {0} ....", System::ObjectExt::Box<System::String>(messageInfo->get_Subject()));
            // get the message in MapiMessage instance
            System::SharedPtr<MapiMessage> message = pst->ExtractMessage(messageInfo);
            // save this message to disk in msg format
            message->Save(message->get_Subject().Replace(u":", u" ") + u".msg");
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
    System::String path = dataDir + u"PersonalStorage.pst";
    
    try
    {
        // load the Outlook PST file
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
        
        // get the Display Format of the PST file
        System::Console::WriteLine(System::String(u"Display Format: ") + System::ObjectExt::ToString(pst->get_Format()));
        
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


