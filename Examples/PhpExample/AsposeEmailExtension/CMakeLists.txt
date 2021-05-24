cmake_minimum_required(VERSION 3.5)
set (target AsposeEmailExtension)
project(${target} LANGUAGES CXX)

set(CMAKE_SHARED_LIBRARY_PREFIX_бее "")

# following variables should be set (either in CMakeLists.txt or as environment variables)
# ASPOSE_ROOT     Path to the root of Aspose.Email for C++ distributions. Cmake config files aspose.email.cpp-config.cmake and codeporting.native.cs2cpp-config.cmake must be located there.
# ASPOSE_EMAIL_CPP_ROOT  Path to Aspose.Email for C++ distributions 
# PHP_INCLUDE_DIR      Path to PHP include dir (on linux retrieved by 'php-config --include-dir')
# PHP_WIN_LIB       For windows build - path to php precompiled libraries (included in develper pack distribution)
# PHP_WIN_DLL       For windows build - path to php binaries dir 

macro(CheckVariable VARNAME)

if(DEFINED ${VARNAME})
    message(STATUS "Using ${VARNAME} value from cmake: ${${VARNAME}}")
elseif(DEFINED ENV{${VARNAME}})
    set(${VARNAME} $ENV{${VARNAME}})
    message(STATUS "Using ${VARNAME} value from environment: ${${VARNAME}}")
else()
    message(FATAL_ERROR "${VARNAME} not set")
endif()
file(TO_CMAKE_PATH "${${VARNAME}}" ${VARNAME})

endmacro()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

CheckVariable(ASPOSE_ROOT)
CheckVariable(ASPOSE_EMAIL_CPP_ROOT)
CheckVariable(PHP_INCLUDE_DIR)
if (MSVC)
    CheckVariable(PHP_WIN_LIB)
    CheckVariable(PHP_WIN_DLL)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Cpp/cmake")

include(SetLibraryOutputDir)
SetOutputDirectory()

include(OptionsCommon)
#include(SetLibraryOutputName)
include(GroupSources)

include(GuessCompilerPrefix)
GUESS_COMPILER_PREFIX(compiler_prefix)

find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_EMAIL_CPP_ROOT})

# package configuration for pre-build php
if (MSVC)
add_library(php SHARED IMPORTED)
#add_library(php INTERFACE)

set_target_properties(php PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDE_DIR};${PHP_INCLUDE_DIR}/main;${PHP_INCLUDE_DIR}/TSRM;${PHP_INCLUDE_DIR}/Zend;"
)

set_property(TARGET php APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(php PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${PHP_WIN_LIB}/php7.lib"
  IMPORTED_LOCATION_DEBUG "${PHP_WIN_DLL}/php7.dll"
  )
target_compile_definitions(php INTERFACE PHP_WIN32 ZEND_WIN32 ZEND_DEBUG=0 ZEND_WIN32_KEEP_INLINE PHP_ATOM_INC)

else()

add_library(php INTERFACE)
set_target_properties(php PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDE_DIR};${PHP_INCLUDE_DIR}/main;${PHP_INCLUDE_DIR}/TSRM;${PHP_INCLUDE_DIR}/Zend;"
)
target_compile_definitions(php INTERFACE ZEND_DEBUG=0 PHP_ATOM_INC)

endif()

add_library(${target} SHARED 
AsposeEmailExtension.cpp
AsposeEmailConvertor.cpp
)

set_target_properties(${target} PROPERTIES PREFIX "")

target_link_libraries(${target} PRIVATE Aspose.Email.Cpp)
#target_link_libraries(${target} PRIVATE Aspose::CodePorting.Native.Cs2Cpp)
#target_link_libraries(${target} PRIVATE CodePorting.Native.Cs2Cpp)
target_link_libraries(${target} PRIVATE php)


add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Native.Cs2Cpp>
        $<TARGET_FILE_DIR:${target}>)        
