#include <napi.h>
#include <string>
#include "greeting.hpp"
#include "AsposeEmailConvetor.h"

Napi::Value greetingHello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  auto user = static_cast<std::string>(info[0].ToString());
  helloUser(user);

  return Napi::Value{};
}

std::string ConvertMailMessageToHtml(const std::string& fileName);
std::string ConvertMailMessageFile(const std::string& fileName, const std::string& outputFileName, const std::string& outputType);
std::string LoadLicense(std::string licenseFileName);

Napi::Value ConvertMailMessageToHtml(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    auto fileName = static_cast<std::string>(info[0].ToString());

    //return Napi::Value{};
    return Napi::Value::From(env, "");
}

Napi::Value ConvertMailMessageFile(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //turn Napi::Value{};
    return Napi::Value::From(env, "");
}

Napi::Value LoadLicense(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //return Napi::Value{};
    return Napi::Value::From(env, "");
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "greetHello"),
              Napi::Function::New(env, greetingHello));

  exports.Set(Napi::String::New(env, "ConvertMailMessageToHtml"),
      Napi::Function::New(env, ConvertMailMessageToHtml));

  exports.Set(Napi::String::New(env, "ConvertMailMessageFile"),
      Napi::Function::New(env, ConvertMailMessageFile));

  exports.Set(Napi::String::New(env, "LoadLicense"),
      Napi::Function::New(env, LoadLicense));

  return exports;
}

NODE_API_MODULE(aspose_words, Init)