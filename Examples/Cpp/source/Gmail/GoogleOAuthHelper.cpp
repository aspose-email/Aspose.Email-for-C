// ExStart:GoogleOAuthHelper
#include "GoogleOAuthHelper.h"

#include <system/web/http_utility.h>
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/text_reader.h>
#include <system/io/stream_reader.h>
#include <system/io/stream.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/diagnostics/debug.h>
#include <system/details/dispose_guard.h>
#include <system/convert.h>
#include <system/array.h>
#include <net/web_response.h>
#include <net/web_request.h>
#include <net/http_web_response.h>
#include <net/http_web_request.h>
#include <net/cookie_container.h>

#include <cstdint>

#include "Gmail/TestUser.h"
#include "Gmail/GoogleTestUser.h"

const System::String GoogleOAuthHelper::TOKEN_REQUEST_URL = u"https://www.googleapis.com/oauth2/v4/token";


System::String GoogleOAuthHelper::GetAccessTokenByRefreshToken(const GoogleTestUser& user)
{
    System::String access_token;
    System::String token_type;
    int32_t expires_in;
    GetAccessTokenByRefreshToken(user, access_token, token_type, expires_in);
    return access_token;
}

void GoogleOAuthHelper::GetAccessTokenByRefreshToken(const GoogleTestUser& user, System::String& access_token, System::String& token_type, int32_t& expires_in)
{
    access_token.reset();
    token_type.reset();
    expires_in = 0;
    System::SharedPtr<System::Net::HttpWebRequest> request = System::Cast<System::Net::HttpWebRequest>(System::Net::WebRequest::Create(TOKEN_REQUEST_URL));
    request->set_CookieContainer(System::MakeObject<System::Net::CookieContainer>());
    request->set_Method(u"POST");
    request->set_ContentType(u"application/x-www-form-urlencoded");
    System::String encodedParameters = System::String::Format(u"client_id={0}&client_secret={1}&refresh_token={2}&grant_type={3}",
        System::Web::HttpUtility::UrlEncode(user.ClientId),
        System::Web::HttpUtility::UrlEncode(user.ClientSecret),
        System::Web::HttpUtility::UrlEncode(user.RefreshToken),
        System::Web::HttpUtility::UrlEncode(u"refresh_token"));
    System::ArrayPtr<uint8_t> requestData = System::Text::Encoding::get_UTF8()->GetBytes(encodedParameters);
    request->set_ContentLength(requestData->get_Length());
    if (requestData->get_Length() > 0)
    {
        {
            System::SharedPtr<System::IO::Stream> stream = request->GetRequestStream();
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ stream});
            // ------------------------------------------
            
            try
            {
                stream->Write(requestData, 0, requestData->get_Length());
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
    }
    System::SharedPtr<System::Net::HttpWebResponse> response = System::Cast<System::Net::HttpWebResponse>(request->GetResponse());
    System::String responseText;
    {
        System::SharedPtr<System::IO::TextReader> reader = System::MakeObject<System::IO::StreamReader>(response->GetResponseStream(), System::Text::Encoding::get_ASCII());
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ reader});
        // ------------------------------------------
        
        try
        {
            responseText = reader->ReadToEnd();
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
    System::ArrayPtr<System::String> strs = responseText.Replace(u"{", u"").Replace(u"}", u"").Replace(u"\"", u"").Replace(u"\n", u"").Replace(u"\r", u"").Split(System::MakeArray<System::String>({u","}), System::StringSplitOptions::None);
    
    {
        for (System::String sPair : strs)
        {
            System::ArrayPtr<System::String> pair = sPair.Split(System::MakeArray<char16_t>({u':'}));
            System::String name = pair[0].Trim().ToLower();
            System::String value = System::Web::HttpUtility::UrlDecode(pair[1].Trim());
            {
                const System::String& switch_value_0 = name;
                do {
                    if (switch_value_0 == u"access_token")
                    {
                        access_token = value;
                        break;
                    }
                    if (switch_value_0 == u"token_type")
                    {
                        token_type = value;
                        break;
                    }
                    if (switch_value_0 == u"expires_in")
                    {
                        expires_in = System::Convert::ToInt32(value);
                        break;
                    }
                } while (false);
            }
        }
        
    }
    System::Diagnostics::Debug::WriteLine(u"");
    System::Diagnostics::Debug::WriteLine(u"---------------------------------------------------------");
    System::Diagnostics::Debug::WriteLine(u"-----------OAuth 2.0 authorization information-----------");
    System::Diagnostics::Debug::WriteLine(u"---------------------------------------------------------");
    System::Diagnostics::Debug::WriteLine(System::String::Format(u"Login: '{0}'",user.EMail));
    System::Diagnostics::Debug::WriteLine(System::String::Format(u"Access token: '{0}'",access_token));
    System::Diagnostics::Debug::WriteLine(System::String::Format(u"Token type: '{0}'",token_type));
    System::Diagnostics::Debug::WriteLine(System::String::Format(u"Expires in: '{0}'",expires_in));
    System::Diagnostics::Debug::WriteLine(u"---------------------------------------------------------");
    System::Diagnostics::Debug::WriteLine(u"");
}
