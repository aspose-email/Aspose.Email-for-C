cmake_minimum_required(VERSION 3.15)
set (target mail_converter)
project(${target} LANGUAGES CXX)

set (ASPOSE_ROOT "C:/project/Release/Release_25.1/Aspose.Email_for_C++_25.1")

# check ASPOSE_ROOT is set
if(DEFINED ASPOSE_ROOT)
    message(STATUS "Using ASPOSE_ROOT value from cmake: ${ASPOSE_ROOT}")
elseif(DEFINED ENV{ASPOSE_ROOT})
    set(ASPOSE_ROOT $ENV{ASPOSE_ROOT})
    message(STATUS "Using ASPOSE_ROOT value from environment: ${ASPOSE_ROOT}")
else()
    message(ERROR "ASPOSE_ROOT not set")
endif()
file(TO_CMAKE_PATH "${ASPOSE_ROOT}" ASPOSE_ROOT)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB SOURCE_FILES src/*.cpp)

# Create a shared library for Node.js
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${target} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> )

# Set the correct extension for the Node.js module
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Include N-API wrappers
# https://napi.inspiredware.com/build-tools/cmake-js.html
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

# Include N-API wrappers
target_include_directories (${PROJECT_NAME}
    PRIVATE "${NODE_ADDON_API_DIR}"
)

# Specify the Node.js header file paths (through CMake.js)
include_directories(${CMAKE_JS_INC})

# Specify dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_JS_LIB})

# Find the required packages for Aspose.Email for C++
find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})

# Link the dependencies to the project
target_link_libraries(${target} PRIVATE Aspose.Email.Cpp)
target_link_libraries(${target} PRIVATE Aspose::CodePorting.Translator.Cs2Cpp.Framework)
target_link_libraries(${target} PRIVATE CodePorting.Translator.Cs2Cpp.Framework)

# Copy the necessary shared library files after build
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      

add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework>
        $<TARGET_FILE_DIR:${target}>)        
