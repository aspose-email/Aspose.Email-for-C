/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Clients/Imap/ImapFolderInfoCollection.h>
#include <Clients/Imap/ImapFolderInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients::Imap;

void IMAP4ExtendedListCommand()
{
    //ExStart:IMAP4ExtendedListCommand
    {
        System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.gmail.com", 993, u"username", u"password");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ client});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<ImapFolderInfoCollection> folderInfoCol = client->ListFolders(u"*");
            System::Console::WriteLine(System::String(u"Extended List Supported: ") + client->get_ExtendedListSupported());
            
            {
                for (auto&& folderInfo : System::IterateOver(folderInfoCol))
                {
                    {
                        const System::String& switch_value_0 = folderInfo->get_Name();
                        do {
                            if (switch_value_0 == u"[Gmail]/All Mail")
                            {
                                System::Console::WriteLine(System::String(u"Has Children: ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Bin")
                            {
                                System::Console::WriteLine(System::String(u"Bin has children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Drafts")
                            {
                                System::Console::WriteLine(System::String(u"Drafts has children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Important")
                            {
                                System::Console::WriteLine(System::String(u"Important has Children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Sent Mail")
                            {
                                System::Console::WriteLine(System::String(u"Sent Mail has Children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Spam")
                            {
                                System::Console::WriteLine(System::String(u"Spam has Children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                            if (switch_value_0 == u"[Gmail]/Starred")
                            {
                                System::Console::WriteLine(System::String(u"Starred has Children? ") + folderInfo->get_HasChildren());
                                break;
                            }
                        } while (false);
                    }
                }
            }
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    //ExEnd:IMAP4ExtendedListCommand
}

