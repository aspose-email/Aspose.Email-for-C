: Aspose.Email for C++ zip distribution must be used to build applications with CMake command
: set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
: directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

:SET ASPOSE_ROOT=C:\project\asposecpplib
:C:\project\Release\Release_22.2\Aspose.Email_for_C++_22.2
:SET ASPOSE_EMAIL_CPP_ROOT=C:\project\net\tmp\Aspose.Email.Cpp
:ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_22.2\Aspose.Email_for_C++_22.2

set PreferredToolArchitecture=x64
SET ASPOSE_ROOT=C:\project\Release\Release_23.7\Aspose.Email_for_C++_23.7
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_23.7\Aspose.Email_for_C++_23.7

:SET ASPOSE_ROOT=C:\project\asposecpplib
:SET ASPOSE_ROOT=C:\project\asposecpplib.release

:SET ASPOSE_ROOT=C:\project\Release\CodePorting.Translator.Cs2Cpp_internal_23.7
:SET ASPOSE_EMAIL_CPP_ROOT=C:\project\net\tmp\Aspose.Email.Cpp




rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug 
: -DCMAKE_UNITY_BUILD=ON -DCMAKE_UNITY_BUILD_BATCH_SIZE=32 -DENABLE_CYCLES_DETECTION_EXT=1 
if %errorlevel% neq 0 goto error
cmake --build . --config Debug --parallel 5
:error