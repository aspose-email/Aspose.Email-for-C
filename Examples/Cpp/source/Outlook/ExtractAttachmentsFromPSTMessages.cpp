/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <Mapi/MapiAttachment.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

void ExtractAttachmentsFromPSTMessages()
{
    // The path to the File directory.
    // ExStart:ExtractAttachmentsFromPSTMessages
    System::String dataDir = GetDataDir_Outlook();
    
    {
        System::SharedPtr<PersonalStorage> personalstorage = PersonalStorage::FromFile(dataDir + u"Outlook.pst");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalstorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> folder = personalstorage->get_RootFolder()->GetSubFolder(u"Inbox");
            
            
            {
                for (auto&& messageInfo : System::IterateOver(folder->EnumerateMessagesEntryId()))
                {
                    System::SharedPtr<MapiAttachmentCollection> attachments = personalstorage->ExtractAttachments(messageInfo);
                    
                    if (attachments->get_Count() != 0)
                    {
                        for (auto&& attachment : attachments)
                        {
                            if (!System::String::IsNullOrEmpty(attachment->get_LongFileName()))
                            {
                                if (attachment->get_LongFileName().Contains(u".msg"))
                                {
                                    continue;
                                }
                                else
                                {
                                    attachment->Save(dataDir + u"\\Attachments\\" + attachment->get_LongFileName());
                                }
                            }
                        }
                    }
                }
            }
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:ExtractAttachmentsFromPSTMessages
}

