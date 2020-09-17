# Aspose.Email for C++ zip distribution must be used to build qt applications
# nuget packages not yet supported
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

SET ASPOSE_ROOT=C:\project\asposecpplib
SET ASPOSE_EMAIL_CPP_ROOT=C:\project\net.master\tmp\Aspose.Email.Cpp


mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" 
if %errorlevel% neq 0 goto :error
cmake --build . --config Debug
:error