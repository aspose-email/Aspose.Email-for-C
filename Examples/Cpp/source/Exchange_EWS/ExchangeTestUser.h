#pragma once 
#include <system/string.h>

#include "../Gmail/TestUser.h"

class ExchangeTestUser : public TestUser
{
public:
    System::String MailboxUri;


    ExchangeTestUser(System::String mailboxUri, System::String username, System::String password, System::String domain = System::String()) : TestUser(username, System::String(), password, domain)
    {
        MailboxUri = mailboxUri;
    }
};
