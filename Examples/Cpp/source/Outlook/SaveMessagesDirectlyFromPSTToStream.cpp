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
#include <system/io/memory_stream.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageInfo.h>
#include <Storage/Pst/FolderInfo.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void SaveMessagesDirectlyFromPSTToStream()
{
    // ExStart:SaveMessagesDirectlyFromPSTToStream
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorage.pst";
    
    // Save message to MemoryStream
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> inbox = personalStorage->get_RootFolder()->GetSubFolder(u"Inbox");
            
            {
                auto messageInfo_enumerator = (inbox->EnumerateMessages())->GetEnumerator();
                decltype(messageInfo_enumerator->get_Current()) messageInfo;
                while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
                {
                    {
                        System::SharedPtr<System::IO::MemoryStream> memeorystream = System::MakeObject<System::IO::MemoryStream>();
                        // Clearing resources under 'using' statement
                        System::Details::DisposeGuard<1> __dispose_guard_0({ memeorystream});
                        // ------------------------------------------
                        
                        try
                        {
                            personalStorage->SaveMessageToStream(messageInfo->get_EntryIdString(), memeorystream);
                        }
                        catch(...)
                        {
                            __dispose_guard_0.SetCurrentException(std::current_exception());
                        }
                    }
                }
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    
    // Save message to file
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_3({ pst});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> inbox = pst->get_RootFolder()->GetSubFolder(u"Inbox");
            
            {
                auto messageInfo_enumerator = (inbox->EnumerateMessages())->GetEnumerator();
                decltype(messageInfo_enumerator->get_Current()) messageInfo;
                while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
                {
                    {
                        System::SharedPtr<System::IO::FileStream> fs = System::IO::File::OpenWrite(messageInfo->get_Subject() + u".msg");
                        // Clearing resources under 'using' statement
                        System::Details::DisposeGuard<1> __dispose_guard_2({ fs});
                        // ------------------------------------------
                        
                        try
                        {
                            pst->SaveMessageToStream(messageInfo->get_EntryIdString(), fs);
                        }
                        catch(...)
                        {
                            __dispose_guard_2.SetCurrentException(std::current_exception());
                        }
                    }
                }
            }
        }
        catch(...)
        {
            __dispose_guard_3.SetCurrentException(std::current_exception());
        }
    }
    
    {
        System::SharedPtr<PersonalStorage> pst = PersonalStorage::FromFile(path);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_5({ pst});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> inbox = pst->get_RootFolder()->GetSubFolder(u"Inbox");
            
            // To enumerate entryId of messages you may use FolderInfo.EnumerateMessagesEntryId() method:
            
            {
                auto entryId_enumerator = (inbox->EnumerateMessagesEntryId())->GetEnumerator();
                decltype(entryId_enumerator->get_Current()) entryId;
                while (entryId_enumerator->MoveNext() && (entryId = entryId_enumerator->get_Current(), true))
                {
                    {
                        System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
                        // Clearing resources under 'using' statement
                        System::Details::DisposeGuard<1> __dispose_guard_4({ ms});
                        // ------------------------------------------
                        
                        try
                        {
                            pst->SaveMessageToStream(entryId, ms);
                        }
                        catch(...)
                        {
                            __dispose_guard_4.SetCurrentException(std::current_exception());
                        }
                    }
                }
            }
        }
        catch(...)
        {
            __dispose_guard_5.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:SaveMessagesDirectlyFromPSTToStream
}

