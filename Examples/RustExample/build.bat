rmdir /Q /S  build
rmdir /Q /S  target
cmake -B build  -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release