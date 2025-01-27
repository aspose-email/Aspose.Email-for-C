#pragma once

#include <string>

std::string ConvertMailMessageToHtml(const std::string& fileName);
std::string ConvertMailMessageFile(const std::string& fileName, const std::string& outputFileName, const std::string& outputType);
std::string LoadLicense(std::string licenseFileName);

/*
extern "C" {
const char *ConvertMailMessageToHtml(const char *fileName);
const char *ConvertMailMessageFile(const char *fileName, const char *outputFileName, const char *outputType);
const char *LoadLicense(const char *licenseFileName);
}
*/