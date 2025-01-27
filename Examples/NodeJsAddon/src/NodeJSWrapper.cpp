#include <napi.h>
#include <string>

#include "AsposeEmailConvertor.h"

// Враппер для ConvertMailMessageToHtml
Napi::Value ConvertMailMessageToHtmlWrapper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "Expected a single string argument").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string fileName = info[0].As<Napi::String>();
    std::string result = ConvertMailMessageToHtml(fileName);

    return Napi::String::New(env, result);
}

// Враппер для ConvertMailMessageFile
Napi::Value ConvertMailMessageFileWrapper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 3 || !info[0].IsString() || !info[1].IsString() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Expected three string arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string fileName = info[0].As<Napi::String>();
    std::string outputFileName = info[1].As<Napi::String>();
    std::string outputType = info[2].As<Napi::String>();

    std::string result = ConvertMailMessageFile(fileName, outputFileName, outputType);

    return Napi::String::New(env, result);
}

// Враппер для LoadLicense
Napi::Value LoadLicenseWrapper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "Expected a single string argument").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string licenseFileName = info[0].As<Napi::String>();
    std::string result = LoadLicense(licenseFileName);

    return Napi::String::New(env, result);
}

// Регистрация модулей
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "convertMailMessageToHtml"), Napi::Function::New(env, ConvertMailMessageToHtmlWrapper));
    exports.Set(Napi::String::New(env, "convertMailMessageFile"), Napi::Function::New(env, ConvertMailMessageFileWrapper));
    exports.Set(Napi::String::New(env, "loadLicense"), Napi::Function::New(env, LoadLicenseWrapper));

    return exports;
}

NODE_API_MODULE(mail_converter, Init)
