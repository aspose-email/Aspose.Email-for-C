/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;
using namespace Aspose::Email::Outlook::Pst;


void ExtractAttachmentsFromPSTMessages()
{
    // The path to the File directory.
    // ExStart:ExtractAttachmentsFromPSTMessages
    System::String dataDir = GetDataDir_Outlook();
    
    {
        System::SharedPtr<PersonalStorage> personalstorage = PersonalStorage::FromFile(dataDir + L"Outlook.pst");
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ personalstorage, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        System::SharedPtr<FolderInfo> folder = personalstorage->get_RootFolder()->GetSubFolder(L"Inbox");
        
        
        {
            auto messageInfo_enumerator = (folder->EnumerateMessagesEntryId())->GetEnumerator();
            decltype(messageInfo_enumerator->get_Current()) messageInfo;
            while (messageInfo_enumerator->MoveNext() && (messageInfo = messageInfo_enumerator->get_Current(), true))
            {
                System::SharedPtr<MapiAttachmentCollection> attachments = personalstorage->ExtractAttachments(messageInfo);
                
                if (attachments->get_Count() != 0)
                {
                    auto attachment_enumerator = (attachments)->GetEnumerator();
                    decltype(attachment_enumerator->get_Current()) attachment;
                    while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
                    {
                        if (!System::String::IsNullOrEmpty(attachment->get_LongFileName()))
                        {
                            if (attachment->get_LongFileName().Contains(L".msg"))
                            {
                                continue;
                            }
                            else
                            {
                                attachment->Save(dataDir + L"\\Attachments\\" + attachment->get_LongFileName());
                            }
                        }
                    }
                }
            }
        }
    }
    // ExEnd:ExtractAttachmentsFromPSTMessages
}







