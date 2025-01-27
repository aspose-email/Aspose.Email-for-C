# Aspose.Email for C++ zip distribution must be used to build applications with CMake command
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

set PreferredToolArchitecture=x64
set ASPOSE_ROOT=C:\project\Release\Release_25.1\Aspose.Email_for_C++_25.1
set ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_25.1\Aspose.Email_for_C++_25.1

rmdir /Q /S buildDeb
mkdir buildDeb
cd buildDeb
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 goto error
cmake --build . --config Debug
if %errorlevel% neq 0 goto error

cmake --install . --config Debug --prefix install

echo OK
exit /b 0
:error
echo ERROR
exit %errorlevel%