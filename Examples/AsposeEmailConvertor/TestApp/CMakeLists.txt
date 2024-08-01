cmake_minimum_required(VERSION 3.21)
set (target EmailConvertorTestApp)
project(${target} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EMAIL_CONVERTOR_PATH "../../AsposeEmailConvertor")
message(STATUS "EMAIL_CONVERTOR_PATH: ${EMAIL_CONVERTOR_PATH}")
#include(${EMAIL_CONVERTOR_PATH}/AsposeEmailConvertorConfig.cmake)
find_package(AsposeEmailConvertor REQUIRED CONFIG PATHS ${EMAIL_CONVERTOR_PATH})

add_executable(${target}
    testapp.cpp
)

target_link_libraries(${target} PRIVATE AsposeEmailConvertor)

add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
        $<TARGET_FILE_DIR:AsposeEmailConvertor>
        $<TARGET_FILE_DIR:${target}>)      
