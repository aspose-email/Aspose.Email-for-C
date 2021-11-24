#pragma once

#include <stdio.h>

void ConvertMailMessageToHtml(const char* fileName, char *out);
void ConvertMailMessageFile(const char*  fileName, const char*  outputFileName, const char*  outputType, char *out);
void LoadLicense(const char*  licenseFileName, char *out);
