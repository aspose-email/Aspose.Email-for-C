export ASPOSE_ROOT="/mnt/c/project/Release/Release_21.3/Aspose.Email_for_C++_21.3"
export ASPOSE_EMAIL_CPP_ROOT="/mnt/c/project/Release/Release_21.3/Aspose.Email_for_C++_21.3"
export PHP_INCLUDE_DIR="/usr/include/php/20151012"


export CC="gcc"
export CXX="g++"

rm -rf "build"
mkdir "build"
cd "build"
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]
then
  cmake --build . --config Release -- -j5
fi
