#include "Examples.h"
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enumerator_adapter.h>
#include <system/convert.h>
#include <system/console.h>
#include <Clients/Exchange/WebService/EWSClient/IEWSClient.h>
#include <Clients/Exchange/WebService/EWSClient/EWSClient.h>
#include <Clients/Exchange/ExchangePermissionCollection.h>
#include <Clients/Exchange/ExchangeMailboxInfo.h>
#include <Clients/Exchange/ExchangeFolderUserInfo.h>
#include <Clients/Exchange/ExchangeFolderPermissionReadAccess.h>
#include <Clients/Exchange/ExchangeFolderPermissionCollection.h>
#include <Clients/Exchange/ExchangeFolderPermissionAction.h>
#include <Clients/Exchange/ExchangeFolderPermission.h>
#include <Clients/Exchange/ExchangeFolderInfoCollection.h>
#include <Clients/Exchange/ExchangeFolderInfo.h>
#include <Clients/Exchange/ExchangeBasePermission.h>

using namespace Aspose::Email::Clients::Exchange::WebService;
using namespace Aspose::Email::Clients::Exchange;

void RetrieveFolderPermissionsUsingExchangeWebServiceClient()
{
    System::String folderName = u"DesiredFolderName";
    
    // Create instance of EWSClient class by giving credentials
    System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

    try
    {
        System::SharedPtr<ExchangeFolderInfoCollection> folders = client->ListPublicFolders();
        System::SharedPtr<ExchangeFolderPermissionCollection> permissions = System::MakeObject<ExchangeFolderPermissionCollection>();

        System::SharedPtr<ExchangeFolderInfo> publicFolder;

        for (auto folderInfo : System::IterateOver(folders))
        {
            if (System::ObjectExt::Equals(folderInfo->get_DisplayName(), folderName))
            {
                publicFolder = folderInfo;
            }
        }

        if (publicFolder == nullptr)
        {
            System::Console::WriteLine(u"public folder was not created in the root public folder");
        }

        System::SharedPtr<ExchangePermissionCollection> folderPermissionCol = client->GetFolderPermissions(publicFolder->get_Uri());
        for (auto perm : System::IterateOver(folderPermissionCol))
        {
            System::SharedPtr<ExchangeFolderPermission> permission = System::ExplicitCast<Aspose::Email::Clients::Exchange::ExchangeFolderPermission>(perm);
            if (permission == nullptr)
            {
                System::Console::WriteLine(u"Permission is null.");
            }
            else
            {
                System::Console::WriteLine(u"User's primary smtp address: {0}", System::ObjectExt::Box<System::String>(permission->get_UserInfo()->get_PrimarySmtpAddress()));
                System::Console::WriteLine(u"User can create Items: {0}", System::ObjectExt::Box<System::String>(System::Convert::ToString(permission->get_CanCreateItems())));
                System::Console::WriteLine(u"User can delete Items: {0}", System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(permission->get_DeleteItems())));
                System::Console::WriteLine(u"Is Folder Visible: {0}", System::ObjectExt::Box<System::String>(System::Convert::ToString(permission->get_IsFolderVisible())));
                System::Console::WriteLine(u"Is User owner of this folder: {0}", System::ObjectExt::Box<System::String>(System::Convert::ToString(permission->get_IsFolderOwner())));
                System::Console::WriteLine(u"User can read items: {0}", System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(permission->get_ReadItems())));
            }
        }
        System::SharedPtr<ExchangeMailboxInfo> mailboxInfo = client->GetMailboxInfo();
        //Get the Permissions for the Contacts and Calendar Folder
        System::SharedPtr<ExchangePermissionCollection> contactsPermissionCol = client->GetFolderPermissions(mailboxInfo->get_ContactsUri());
        System::SharedPtr<ExchangePermissionCollection> calendarPermissionCol = client->GetFolderPermissions(mailboxInfo->get_CalendarUri());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }

}

