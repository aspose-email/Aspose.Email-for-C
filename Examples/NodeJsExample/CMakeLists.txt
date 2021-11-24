macro(CheckVariable VARNAME)

# SET path to Aspose.Email for C++ distribution here (or in Exvironment variables)
SET(ASPOSE_ROOT C:/project/Release/Release_21.11/Aspose.Email_for_C++_21.11)
SET(ASPOSE_EMAIL_CPP_ROOT C:/project/Release/Release_21.11/Aspose.Email_for_C++_21.11)


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

cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(aspose.email)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

CheckVariable(ASPOSE_ROOT)
CheckVariable(ASPOSE_EMAIL_CPP_ROOT)


add_library(aspose.email SHARED src/greeting.cpp src/greeting.hpp src/index.cpp src/AsposeEmailConvertor.cpp src/AsposeEmailConvetor.h)
set_target_properties(aspose.email PROPERTIES PREFIX "" SUFFIX ".node")
target_include_directories(aspose.email PRIVATE ${CMAKE_JS_INC})

# Include node-addon-api wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(aspose.email PRIVATE ${NODE_ADDON_API_DIR})

target_compile_definitions(aspose.email PRIVATE NAPI_VERSION=3)


find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_EMAIL_CPP_ROOT})
find_package(Threads REQUIRED)


target_link_libraries(aspose.email ${CMAKE_JS_LIB} Aspose.Email.Cpp Threads::Threads)
target_compile_options(aspose.email PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/wd4244 /wd4250 /wd4267 /MP /bigobj /utf-8>)

add_custom_command(TARGET aspose.email POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:aspose.email> $<TARGET_FILE_DIR:aspose.email>
  COMMAND_EXPAND_LISTS
  )