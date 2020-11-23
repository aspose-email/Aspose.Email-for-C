cmake_minimum_required(VERSION 3.5)
set (target SampleProject)
project(${target} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ASPOSE_ROOT)
    message(STATUS "Using ASPOSE_ROOT value from cmake: ${ASPOSE_ROOT}")
elseif(DEFINED ENV{ASPOSE_ROOT})
    set(ASPOSE_ROOT $ENV{ASPOSE_ROOT})
    message(STATUS "Using ASPOSE_ROOT value from environment: ${ASPOSE_ROOT}")
else()
    message(ERROR "ASPOSE_ROOT not set")
endif()
file(TO_CMAKE_PATH "${ASPOSE_ROOT}" ASPOSE_ROOT)

if(DEFINED ASPOSE_EMAIL_CPP_ROOT)
    message(STATUS "Using ASPOSE_EMAIL_CPP_ROOT value from cmake: ${ASPOSE_EMAIL_CPP_ROOT}")
elseif(DEFINED ENV{ASPOSE_EMAIL_CPP_ROOT})
    set(ASPOSE_EMAIL_CPP_ROOT $ENV{ASPOSE_EMAIL_CPP_ROOT})
    message(STATUS "ASPOSE_EMAIL_CPP_ROOT: ${ASPOSE_EMAIL_CPP_ROOT}")
else()
    message(ERROR "ASPOSE_EMAIL_CPP_ROOT is not set")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/cmake")
include(OptionsCommon)
include(SetLibraryOutputName)
include(GroupSources)

include(GuessCompilerPrefix)
GUESS_COMPILER_PREFIX(compiler_prefix)

find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_EMAIL_CPP_ROOT})

#include("${ASPOSE_EMAIL_CPP_ROOT}/Aspose.Email.Cpp-targets-${compiler_prefix}.cmake")

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS ${Qt5_DIR})

add_executable(${target}
    main.cpp
    AsposeEmailConvertor.cpp
)

target_link_libraries(${target} PRIVATE Qt5::Widgets)
target_link_libraries(${target} PRIVATE Aspose.Email.Cpp)
target_link_libraries(${target} PRIVATE Aspose::CodePorting.Native.Cs2Cpp)
target_link_libraries(${target} PRIVATE CodePorting.Native.Cs2Cpp)


if (WIN32)
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${target} POST_BUILD
       COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:${target}>)
endif(WIN32)

add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Native.Cs2Cpp>
        $<TARGET_FILE_DIR:${target}>)        
