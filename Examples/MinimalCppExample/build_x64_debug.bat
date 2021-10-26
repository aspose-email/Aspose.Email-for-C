# Aspose.Email for C++ zip distribution must be used to build applications with CMake command
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

SET ASPOSE_ROOT=C:\project\Release\Release_21.10\Aspose.Email_for_C++_21.10
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_21.10\Aspose.Email_for_C++_21.10

rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 goto error
cmake --build . --config Debug --parallel 5
:error