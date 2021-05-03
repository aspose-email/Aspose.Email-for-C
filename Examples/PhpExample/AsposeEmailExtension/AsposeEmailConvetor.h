#pragma once

#include <string>

std::string ConvertMailMessageToHtml(const std::string& fileName);
std::string ConvertMailMessageFile(const std::string& fileName, const std::string& outputFileName, const std::string& outputType);
std::string LoadLicense(std::string licenseFileName);
