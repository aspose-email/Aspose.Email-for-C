#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <PersonalInfo/Contact.h>
#include <ObjectIdentifier.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"


using namespace Aspose::Email::Clients::Google;
using namespace Aspose::Email::PersonalInfo;

void DeleteGmailContact()
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
                System::SharedPtr<Contact> contact = contacts[0];
                
                // ExStart:DeleteGmailContact
                client->DeleteContact(contact->get_Id()->get_GoogleId());
                // ExEnd:DeleteGmailContact
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex.get_Message());
    }
    
}
