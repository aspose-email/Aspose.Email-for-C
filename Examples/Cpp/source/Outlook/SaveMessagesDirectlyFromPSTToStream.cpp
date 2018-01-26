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
#include <system/io/memory_stream.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email::Outlook::Pst;


void SaveMessagesDirectlyFromPSTToStream()
{
    // ExStart:SaveMessagesDirectlyFromPSTToStream
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + L"PersonalStorage.pst";
    
    // Save message to MemoryStream
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalStorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> inbox = personalStorage->get_RootFolder()->GetSubFolder(L"Inbox");
        
        {
            auto messageInfo_enumerator = (inbox->EnumerateMessages())->GetEnumerator();
            decltype(messageInfo_enumerator->get_Current()) messageInfo;
            while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
            {
                {
                    System::SharedPtr<System::IO::MemoryStream> memeorystream = System::MakeObject<System::IO::MemoryStream>();
                    
                    // Clearing resources under 'using' statement
                    System::Details::DisposeGuard __dispose_guard_1{ memeorystream, ASPOSE_CURRENT_FUNCTION_LINE };
                    // ------------------------------------------
                    personalStorage->SaveMessageToStream(messageInfo->get_EntryIdString(), memeorystream);
                }
            }
        }
    }
    
    // Save message to file
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_2{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> inbox = pst->get_RootFolder()->GetSubFolder(L"Inbox");
        
        {
            auto messageInfo_enumerator = (inbox->EnumerateMessages())->GetEnumerator();
            decltype(messageInfo_enumerator->get_Current()) messageInfo;
            while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
            {
                {
                    System::SharedPtr<System::IO::FileStream> fs = System::IO::File::OpenWrite(messageInfo->get_Subject() + L".msg");
                    
                    // Clearing resources under 'using' statement
                    System::Details::DisposeGuard __dispose_guard_3{ fs, ASPOSE_CURRENT_FUNCTION_LINE };
                    // ------------------------------------------
                    pst->SaveMessageToStream(messageInfo->get_EntryIdString(), fs);
                }
            }
        }
    }
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_4{ pst, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> inbox = pst->get_RootFolder()->GetSubFolder(L"Inbox");
        
        // To enumerate entryId of messages you may use FolderInfo.EnumerateMessagesEntryId() method:
        
        {
            auto entryId_enumerator = (inbox->EnumerateMessagesEntryId())->GetEnumerator();
            decltype(entryId_enumerator->get_Current()) entryId;
            while (entryId_enumerator->MoveNext() && (entryId = entryId_enumerator->get_Current(), true))
            {
                {
                    System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
                    
                    // Clearing resources under 'using' statement
                    System::Details::DisposeGuard __dispose_guard_5{ ms, ASPOSE_CURRENT_FUNCTION_LINE };
                    // ------------------------------------------
                    pst->SaveMessageToStream(entryId, ms);
                }
            }
        }
    }
    // ExEnd:SaveMessagesDirectlyFromPSTToStream
}







