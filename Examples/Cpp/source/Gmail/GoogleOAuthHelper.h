#pragma once
// ExStart:GoogleOAuthHelper

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <cstdint>

#include "Gmail/GoogleTestUser.h"


class GoogleOAuthHelper
{
public:
    static const System::String TOKEN_REQUEST_URL;
    
    static System::String GetAccessTokenByRefreshToken(const GoogleTestUser& user);
    static void GetAccessTokenByRefreshToken(const GoogleTestUser& user, System::String& access_token, System::String& token_type, int32_t& expires_in);
    
};
