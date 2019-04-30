// ExStart:TestUser
#include "Gmail/TestUser.h"

#include <system/string_comparison.h>
#include <system/string.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>


TestUser::TestUser(System::String name, System::String eMail, System::String password, System::String domain)
{
    Name = name;
    EMail = eMail;
    Password = password;
    Domain = domain;
}
