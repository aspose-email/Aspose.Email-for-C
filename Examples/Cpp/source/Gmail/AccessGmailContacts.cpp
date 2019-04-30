#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <PersonalInfo/EmailAddressList.h>
#include <PersonalInfo/EmailAddress.h>
#include <PersonalInfo/Contact.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Contact/GoogleContactGroup.h>
#include <Clients/Google/Contact/ContactGroupCollection.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Clients::Google;
using namespace Aspose::Email::PersonalInfo;

void AccessGmailContacts()
{
    try
    {
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        // Get IGmailclient
        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                System::ArrayPtr<System::SharedPtr<Contact>> contacts = client->GetAllContacts();
                
                {
                    for (System::SharedPtr<Contact> contact : contacts)
                    {
                        System::Console::WriteLine(contact->get_DisplayName() + u", " + contact->get_EmailAddresses()->idx_get(0));
                    }
                    
                }
                
                // Fetch contacts from a specific group
                System::SharedPtr<ContactGroupCollection> groups = client->GetAllGroups();
                System::SharedPtr<GoogleContactGroup> group;
                
                {
                    auto g_enumerator = (groups)->GetEnumerator();
                    decltype(g_enumerator->get_Current()) g;
                    while (g_enumerator->MoveNext() && (g = g_enumerator->get_Current(), true))
                    {
                        {
                            const System::String& switch_value_0 = g->get_Title();
                            do {
                                if (switch_value_0 == u"TestGroup")
                                {
                                    group = g;
                                    break;
                                }
                            } while (false);
                        }
                    }
                }
                
                // Retrieve contacts from the Group
                if (group != nullptr)
                {
                    System::ArrayPtr<System::SharedPtr<Contact>> contacts2 = client->GetContactsFromGroup(group->get_Id());
                    
                    {
                        for (System::SharedPtr<Contact> con : contacts2)
                        {
                            System::Console::WriteLine(con->get_DisplayName() + u"," + System::ObjectExt::ToString(con->get_EmailAddresses()->idx_get(0)));
                        }
                        
                    }
                }
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:AccessGmailContacts
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
