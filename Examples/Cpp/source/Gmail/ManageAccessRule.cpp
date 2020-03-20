#include <system/shared_ptr.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <Clients/Google/IGmailClient.h>
#include <Clients/Google/GmailClient.h>
#include <Clients/Google/Calendar/ExtendedCalendar.h>
#include <Clients/Google/Calendar/AclScopeType.h>
#include <Clients/Google/Calendar/AclScope.h>
#include <Clients/Google/Calendar/AccessRole.h>
#include <Clients/Google/Calendar/AccessControlRule.h>

#include "Examples.h"
#include "Gmail/GoogleTestUser.h"
#include "Gmail/GoogleOAuthHelper.h"

using namespace Aspose::Email::Calendar;
using namespace Aspose::Email::Clients::Google;

void ManageAccessRule()
{
    try
    {
        // ExStart:ManageAccessRule
        GoogleTestUser User2 = GetGoogleTestUser();
        System::String accessToken = GoogleOAuthHelper::GetAccessTokenByRefreshToken(User2);

        {
            System::SharedPtr<IGmailClient> client = GmailClient::GetInstance(accessToken, User2.EMail);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ client});
            // ------------------------------------------
            
            try
            {
                // Retrieve list of calendars for the current client
                System::ArrayPtr<System::SharedPtr<ExtendedCalendar>> calendarList = client->ListCalendars();
                
                // Get first calendar id and retrieve list of AccessControlRule for the first calendar
                System::String calendarId = calendarList[0]->get_Id();
                System::ArrayPtr<System::SharedPtr<AccessControlRule>> roles1 = client->ListAccessRules(calendarId);
                
                // Create a local access control rule and Set rule properties
                System::SharedPtr<AccessControlRule> rule = System::MakeObject<AccessControlRule>();
                rule->set_Role(Aspose::Email::Clients::Google::AccessRole::reader);
                rule->set_Scope(System::MakeObject<AclScope>(Aspose::Email::Clients::Google::AclScopeType::user, User2.EMail));
                
                // Insert new rule for the calendar. It returns the newly created rule
                System::SharedPtr<AccessControlRule> createdRule = client->CreateAccessRule(calendarId, rule);
                
                // Confirm if local created rule and returned rule are equal
                if ((rule->get_Role() == createdRule->get_Role()) && (rule->get_Scope()->get_Type() == createdRule->get_Scope()->get_Type()) && (rule->get_Scope()->get_Value().ToLower() == createdRule->get_Scope()->get_Value().ToLower()))
                {
                    System::Console::WriteLine(u"local rule and returned rule after creation are equal");
                }
                else
                {
                    System::Console::WriteLine(u"Rule could not be created successfully");
                    return;
                }
                
                // Get list of rules
                System::ArrayPtr<System::SharedPtr<AccessControlRule>> roles2 = client->ListAccessRules(calendarId);
                
                // Current list length should be 1 more than the earlier one
                if (roles1->get_Length() + 1 == roles2->get_Length())
                {
                    System::Console::WriteLine(u"List lengths are ok");
                }
                else
                {
                    System::Console::WriteLine(u"List lengths are not ok");
                    return;
                }
                
                // Change rule and Update the rule for the selected calendar
                createdRule->set_Role(Aspose::Email::Clients::Google::AccessRole::writer);
                System::SharedPtr<AccessControlRule> updatedRule = client->UpdateAccessRule(calendarId, createdRule);
                
                // Check if returned access control rule after update is ok
                if ((createdRule->get_Role() == updatedRule->get_Role()) && (createdRule->get_Id() == updatedRule->get_Id()))
                {
                    System::Console::WriteLine(u"Rule is updated successfully");
                }
                else
                {
                    System::Console::WriteLine(u"Rule is not updated");
                    return;
                }
                
                // Retrieve individaul rule against a calendar
                System::SharedPtr<AccessControlRule> fetchedRule = client->FetchAccessRule(calendarId, createdRule->get_Id());
                
                //Check if rule parameters are ok
                if ((updatedRule->get_Id() == fetchedRule->get_Id()) && (updatedRule->get_Role() == fetchedRule->get_Role()) && (updatedRule->get_Scope()->get_Type() == fetchedRule->get_Scope()->get_Type()) && (updatedRule->get_Scope()->get_Value().ToLower() == fetchedRule->get_Scope()->get_Value().ToLower()))
                {
                    System::Console::WriteLine(u"Rule parameters are ok");
                }
                else
                {
                    System::Console::WriteLine(u"Rule parameters are not ok");
                }
                
                // Delete particular rule against a given calendar and Retrieve the all rules list for the same calendar
                client->DeleteAccessRule(calendarId, createdRule->get_Id());
                System::ArrayPtr<System::SharedPtr<AccessControlRule>> roles3 = client->ListAccessRules(calendarId);
                
                // Check that current rules list length should be equal to the original list length before adding and deleting the rule
                if (roles1->get_Length() == roles3->get_Length())
                {
                    System::Console::WriteLine(u"List lengths are same");
                }
                else
                {
                    System::Console::WriteLine(u"List lengths are not equal");
                    return;
                }
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:ManageAccessRule
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
}
