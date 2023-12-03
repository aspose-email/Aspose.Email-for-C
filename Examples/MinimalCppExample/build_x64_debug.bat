# Aspose.Email for C++ zip distribution must be used to build applications with CMake command
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

set PreferredToolArchitecture=x64

:SET ASPOSE_ROOT=C:\project\Release\Release_23.7\Aspose.Email_for_C++_23.7
:SET ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_23.7\Aspose.Email_for_C++_23.7

set ASPOSE_ROOT=C:\project\Release\CodePorting.Translator.Cs2Cpp_internal_23.11
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\net\tmp\Aspose.Email.Cpp



rmdir /Q /S buildDeb
mkdir buildDeb
cd buildDeb
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 goto error
cmake --build . --config Debug
:error