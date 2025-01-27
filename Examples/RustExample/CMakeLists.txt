cmake_minimum_required(VERSION 3.15)

set (target aspose_mail_converter)
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
file(GLOB SOURCE_FILES src_cpp/*.cpp)

# Create a shared library for Node.js
add_library(aspose_mail_converter SHARED ${SOURCE_FILES})

target_include_directories(aspose_mail_converter PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src_cpp> )

# Find the required packages for Aspose.Email for C++
find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})

# Link the dependencies to the project
target_link_libraries(aspose_mail_converter PRIVATE Aspose.Email.Cpp)
target_link_libraries(aspose_mail_converter PRIVATE Aspose::CodePorting.Translator.Cs2Cpp.Framework)
target_link_libraries(aspose_mail_converter PRIVATE CodePorting.Translator.Cs2Cpp.Framework)

# Copy the necessary shared library files after build
add_custom_command(TARGET aspose_mail_converter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      

add_custom_command(TARGET aspose_mail_converter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework>
        $<TARGET_FILE_DIR:${target}>)        



# Rust app build
add_custom_target(RustApp ALL
    COMMAND cargo build --release
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Building Rust application"
)

# copy Rust int binary dir
add_custom_command(
    TARGET RustApp
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/target/release/rust_example.exe
            $<TARGET_FILE_DIR:${target}>
)

# Убедимся, что C++ библиотека собирается до сборки Rust приложения
add_dependencies(RustApp aspose_mail_converter)
