// ExStart:GoogleTestUser
#include "Gmail/GoogleTestUser.h"

#include <system/string.h>

#include "Gmail/TestUser.h"

GoogleTestUser::GoogleTestUser(System::String name, System::String eMail, System::String password)
     : GoogleTestUser(name, eMail, password, nullptr, nullptr, nullptr) { }


GoogleTestUser::GoogleTestUser(System::String name, System::String eMail, System::String password, System::String clientId, System::String clientSecret)
     : GoogleTestUser(name, eMail, password, clientId, clientSecret, nullptr) { }


GoogleTestUser::GoogleTestUser(System::String name, System::String eMail, System::String password, System::String clientId, System::String clientSecret, System::String refreshToken)
     : TestUser(name, eMail, password, u"gmail.com")
{
    ClientId = clientId;
    ClientSecret = clientSecret;
    RefreshToken = refreshToken;
}
