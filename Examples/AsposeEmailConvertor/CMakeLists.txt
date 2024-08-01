cmake_minimum_required(VERSION 3.5)
set (target AsposeEmailConvertor)
project(${target} LANGUAGES CXX)

set(CMAKE_SHARED_LIBRARY_PREFIX_бее "")

# following variables should be set (either in CMakeLists.txt or as environment variables)
# ASPOSE_ROOT     Path to the root of Aspose.Email for C++ distributions. Cmake config files aspose.email.cpp-config.cmake and codeporting.native.cs2cpp-config.cmake must be located there.
# ASPOSE_EMAIL_CPP_ROOT  Path to Aspose.Email for C++ distributions 

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

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Cpp/cmake")

#include(SetLibraryOutputDir)
#SetOutputDirectory()

#include(OptionsCommon)
#include(SetLibraryOutputName)
#include(GroupSources)

#include(GuessCompilerPrefix)
#GUESS_COMPILER_PREFIX(compiler_prefix)

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_EMAIL_CPP_ROOT})


add_library(${target} SHARED  
AsposeEmailConvertor.cpp
)

target_include_directories(${target} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )


set_target_properties(${target} PROPERTIES PREFIX "")

target_link_libraries(${target} PRIVATE Aspose.Email.Cpp)
target_link_libraries(${target} PRIVATE Aspose::CodePorting.Translator.Cs2Cpp.Framework)
target_link_libraries(${target} PRIVATE CodePorting.Translator.Cs2Cpp.Framework)

#target_link_libraries(${target} PRIVATE Aspose::CodePorting.Native.Cs2Cpp)
#target_link_libraries(${target} PRIVATE CodePorting.Native.Cs2Cpp)


add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      

add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework>
        $<TARGET_FILE_DIR:${target}>)        

export(TARGETS ${target}  FILE ${target}Config.cmake)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_BINARY_DIR}/${target}Config.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}) 
