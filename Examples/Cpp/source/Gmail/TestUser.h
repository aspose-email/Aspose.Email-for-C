#pragma once
// ExStart:TestUser

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <cstdint>


enum class GrantTypes
{
    authorization_code,
    refresh_token
};

class TestUser
{
public:

    System::String Name;
    System::String EMail;
    System::String Password;
    System::String Domain;
    
    TestUser(System::String name, System::String eMail, System::String password, System::String domain);
};
