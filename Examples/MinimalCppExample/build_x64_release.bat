# Aspose.Email for C++ zip distribution must be used to build applications with CMake command
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

set ASPOSE_ROOT=C:\project\Release\CodePorting.Translator.Cs2Cpp_internal_23.11
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\net\tmp\Aspose.Email.Cpp


rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release
if %errorlevel% neq 0 goto error
cmake --build . --config Release 
:error