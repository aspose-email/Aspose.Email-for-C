# Aspose.Email for C++ zip distribution must be used to build applications with CMake command
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted

export ASPOSE_ROOT="/mnt/c/project/Release/Release_23.7/Aspose.Email_for_C++_23.7"
export ASPOSE_EMAIL_CPP_ROOT="/mnt/c/project/Release/Release_23.7/Aspose.Email_for_C++_23.7"

rm -rf "build"
mkdir "build"
cd "build"
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]
then
  cmake --build . --config Release -- -j5
fi
