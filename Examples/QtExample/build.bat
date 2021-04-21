set Qt5_DIR=C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\
SET ASPOSE_ROOT=C:\project\Release\Release_20.12\Aspose.Email_for_C++_20.12
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_20.12\Aspose.Email_for_C++_20.12

rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release
if %errorlevel% neq 0 goto error
cmake --build . --config Debug --parallel 5
:error