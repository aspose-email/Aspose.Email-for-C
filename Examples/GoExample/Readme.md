# PHP extension sample to utilize features of Aspose.Email for C++ library

The example demonstrates how Go program can use Aspose.Email for C++ library.
Example code can be used as a skeleton for developing other specific applications that utilize different capabilities of the library.

### Prerequisites


1. Aspose.Email for C++ library zip distribution for the platform: https://downloads.aspose.com/.
2. Aspose.Email for C++  license (optional).

### Setup variable in CMakeLists.txt before the build.
  
**Variables list:**

ASPOSE_ROOT, ASPOSE_EMAIL_CPP_ROOT:
Path to the Aspose.Email for C++ distribution folder.
 
For example,  Aspose.Email for C++ version 21.3 comes in zip archive named Aspose.Email_for_C++_21.3.zip, this archive should be extracted somewhere and
path the that folder should be assigned to that variables.
  
### Building process

There are two sample command files that shows how to call cmake to build the PHP extension on Windows and Linux: 
 
* build_linux_gcc.sh
* build_windows_x64.bat

The resulted extension shared library is written in lib folder.

