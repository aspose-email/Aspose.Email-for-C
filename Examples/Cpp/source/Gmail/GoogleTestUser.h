#pragma once
// ExStart:GoogleTestUser

#include <system/string.h>

#include "Gmail/TestUser.h"

class GoogleTestUser : public TestUser
{
public:

    System::String ClientId;
    System::String ClientSecret;
    System::String RefreshToken;
    
    GoogleTestUser(System::String name, System::String eMail, System::String password);
    GoogleTestUser(System::String name, System::String eMail, System::String password, System::String clientId, System::String clientSecret);
    GoogleTestUser(System::String name, System::String eMail, System::String password, System::String clientId, System::String clientSecret, System::String refreshToken);
    
};

