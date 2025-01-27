#include <string>
#include <cstring>

#include "AsposeEmailConvertor.h"
// Экспортируем обертки
extern "C" {

    const char* ConvertMailMessageToHtmlWrapper(const char* fileName) {
        static std::string result;
        ConvertMailMessageToHtml(fileName);
        return result.c_str();
    }

    const char* ConvertMailMessageFileWrapper(const char* fileName, const char* outputFileName, const char* outputType) {
        static std::string result;
        ConvertMailMessageFile(fileName, outputFileName, outputType);
        return result.c_str();
    }

    const char* LoadLicenseWrapper(const char* licenseFileName) {
        static std::string result;
        result = LoadLicense(licenseFileName);
        return result.c_str();
    }
}
