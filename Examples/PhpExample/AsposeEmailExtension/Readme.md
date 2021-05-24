# PHP extension sample to utilize features of Aspose.Email for C++ library

The example demonstrates PHP extension that allows to use Aspose.Email for C++ library.
Example code can be used as a skeleton for developing other specific applications that utilize different capabilities of the library.

## How to build example on Linux and Windows
### Prerequisites


1. Aspose.Email for C++ library zip distribution for the platform: https://downloads.aspose.com/.
2. Aspose.Email for C++  license (optional).

#### Windows platform

Precompiled PHP binaries should be downloaded at https://windows.php.net/download/.

Depends on the web server used, it my be a "thread safe" or a "not thread safe" type of distribution.

Please, read the explanations about "TS" and "NTS" difference at https://windows.php.net/download/.

Two packages have to be downloaded:
* main package (PHP itself)
* development package (precompiled libraries and headers files).

For example, these two packages may be: php-7.4.18-nts-Win32-vc15-x64.zip (main package 'nts') and php-devel-pack-7.4.18-nts-Win32-vc15-x64.zip (development package nts).


#### Linux platform

php-dev package should be installed (command 'apt-get install php-dev').

### Setup variable in CMakeLists.txt before the build.
  
**Variables list:**

ASPOSE_ROOT, ASPOSE_EMAIL_CPP_ROOT:
Path to the Aspose.Email for C++ distribution folder.
 
For example,  Aspose.Email for C++ version 21.3 comes in zip archive named Aspose.Email_for_C++_21.3.zip, this archive should be extracted somewhere and
path the that folder should be assigned to that variables.
  
PHP_INCLUDE_DIR :
 Path to PHP include dir 
  
* on Linux: this path can be obtained by command  'php-config --include-dir'.
* on Windows: it should point to 'include' folder development package.
 
Development package archive 'php-devel-pack-7.4.18-nts-Win32-vc15-x64.zip' is probably extracted at 'c:\soft\php'. Then, variable's values should be at:
PHP_INCLUDE_DIR=C:/soft/Php/php-devel-pack-7.4.18-nts-Win32-vc15-x64/php-7.4.18-devel-vc15-x64/include

PHP_WIN_LIB       
Variable used only for Windows build - it should contain path to the 'lib' folder of development package.
 
Development package archive 'php-devel-pack-7.4.18-nts-Win32-vc15-x64.zip' is probably extracted at 'c:\soft\php'.
 
Then, variable's values should be at:
PHP_WIN_LIB=C:/soft/Php/php-devel-pack-7.4.18-nts-Win32-vc15-x64/php-7.4.18-devel-vc15-x64/lib

PHP_WIN_DLL       
Variable used only for Windows build - it should contain the path to the main package (where phpX.dll resides).
 
Suppose, that main package archive 'php-7.4.18-nts-Win32-vc15-x64.zip' is extracted at 'c:\soft\php'.
  
Then, variable's values should be:

PHP_WIN_DLL=C:/soft/Php/php-7.4.18-nts-Win32-vc15-x64

### Building process

There are two sample command files that shows how to call cmake to build the PHP extension on Windows and Linux: 
 
* build_linux_gcc.sh
* build_windows_x64.bat

The resulted extension shared library is written in lib folder.

The extension binary names are on Windows and Linux platforms respectively:

* AsposeEmailExtension.dll
* AsposeEmailExtension.so


## How to test extension and run sample web applicaion

In the 'lib' folder there are also samples that show how to test extension with 'php' command and how to run a simple php application using built-in php web server.
 
* Windows: run_test.bat run_server.bat
* Linux: run_test.sh and run_server.sh

Sample PHP Web Application contains two files:
 
* index.html
* upload_and_convert.php

Sample web application works as follows: it asks to upload a mail file and to specify the conversion format. After submitting the form, web server (PHP script) translates the file to the required format and sends the converted file back to client.

