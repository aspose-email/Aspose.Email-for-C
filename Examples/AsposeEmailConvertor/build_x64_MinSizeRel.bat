: MinSizeRel

set PreferredToolArchitecture=x64
set ASPOSE_ROOT=C:\project\Release\Release_24.6\Aspose.Email_for_C++_24.6
set ASPOSE_EMAIL_CPP_ROOT=C:\project\Release\Release_24.6\Aspose.Email_for_C++_24.6

rmdir /Q /S buildMinSizeRel
mkdir buildMinSizeRel
cd buildMinSizeRel
cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=MinSizeRel
if %errorlevel% neq 0 goto error
cmake --build . --config Release 
cmake --build . --config MinSizeRel 
:error