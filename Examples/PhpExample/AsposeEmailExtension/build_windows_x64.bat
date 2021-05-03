: Aspose.Email for C++ zip distribution must be used to build applications with CMake command
: set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
: directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

SET ASPOSE_ROOT=C:\project\Release\Release_21.3\Aspose.Email_for_C++_21.3
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_21.3\Aspose.Email_for_C++_21.3
SET PHP_INCLUDE_DIR=C:/soft/Php/php-devel-pack-7.4.18-nts-Win32-vc15-x64/php-7.4.18-devel-vc15-x64/include
SET PHP_WIN_LIB=C:/soft/Php/php-devel-pack-7.4.18-nts-Win32-vc15-x64/php-7.4.18-devel-vc15-x64/lib
SET PHP_WIN_DLL=C:/soft/Php/php-7.4.18-nts-Win32-vc15-x64


rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 goto error
cmake --build . --config Debug --parallel 5
:error