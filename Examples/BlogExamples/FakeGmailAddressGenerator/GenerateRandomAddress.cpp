#include <string> 
#include <chrono>
#include "system/console.h"
#include <MailAddress.h>

std::string GenerateRandSuffix(int suffixLength = 10)
{
    const char16_t pattern[] = u"abcdefghijklmnopqrstuvwxyz0123456789";
    auto patternLength = std::char_traits<char16_t>::length(pattern);
    std::string generatedSuffix;
    generatedSuffix.reserve(suffixLength);
    srand(time(NULL));
    for (int i = 0; i < suffixLength; i++)
    {
        generatedSuffix += pattern[rand() % (patternLength - 1)];
    }
    return generatedSuffix;
}

using namespace System;
using namespace Aspose::Email;

std::string GenerateFakeEmailAddress(std::string address)
{
    auto generatedSuffix = System::String::FromUtf8(GenerateRandSuffix());

    auto originalAddress = System::MakeObject<MailAddress>(System::String(u"some.address@gmail.com"));
    auto generatedAddress = System::MakeObject<MailAddress>(
    originalAddress->get_User() + u"+" + generatedSuffix + u"@" + originalAddress->get_Host());
    Console::WriteLine(generatedAddress);

    return generatedAddress->ToString().ToUtf8String();
 }