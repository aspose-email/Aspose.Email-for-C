cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(Aspose.Email.Examples.Cpp CXX)

set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(DEFINED ASPOSE_ROOT)
    message(STATUS "Using ASPOSE_ROOT value from cmake execute: ${ASPOSE_ROOT}")
elseif(DEFINED ENV{ASPOSE_ROOT})
    set(ASPOSE_ROOT $ENV{ASPOSE_ROOT})
    message(STATUS "Using ASPOSE_ROOT value from environment: ${ASPOSE_ROOT}")
else()
    message(ERROR "ASPOSE_ROOT not set")
endif()
file(TO_CMAKE_PATH "${ASPOSE_ROOT}" ASPOSE_ROOT)

if(DEFINED ASPOSE_EMAIL_CPP_ROOT)
    message(STATUS "Using ASPOSE_EMAIL_CPP_ROOT value from cmake execute: ${ASPOSE_EMAIL_CPP_ROOT}")
elseif(DEFINED ENV{ASPOSE_EMAIL_CPP_ROOT})
    set(ASPOSE_EMAIL_CPP_ROOT $ENV{ASPOSE_EMAIL_CPP_ROOT})
    message(STATUS "ASPOSE_EMAIL_CPP_ROOT: ${ASPOSE_EMAIL_CPP_ROOT}")
else()
    message(ERROR "ASPOSE_EMAIL_CPP_ROOT is not set")
endif()

option(USE_PCH "Use precompiled header" ${MSVC})
option(USE_COTIRE "Use compile time reducer" OFF)
option(USE_FASTLINK "Use /debug:fastlink option for MSVC" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" FALSE)
option(BUILD_PORTED_PROJECT "Build ported project" TRUE)
option(BUILD_TESTS "Build tests" TRUE)
option(OPTIMIZE_ALL "Enable optimization options for any build configuration" OFF)
option(NO_CHECKED_CASTS "Disable checked casts" OFF)
option(ENABLE_COVERAGE_REPORT "Enable code coverage report" OFF)

if(OPTIMIZE_ALL)
    if (MSVC)
        STRING(REPLACE "/Zi" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
        STRING(REPLACE "/Od" "/O2" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})        
        STRING(REPLACE "/Ob0" "/Ob2" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})        
        STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})        
    else()
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")
    endif()
endif()

set(ASPOSECPP_NO_CHECKED_CASTS "")
if (NO_CHECKED_CASTS)
    set(ASPOSECPP_NO_CHECKED_CASTS "ASPOSECPP_NO_CHECKED_CASTS")
endif()

# PORTED_PROJECT_TYPE = LIBRARY, APP
set(PORTED_PROJECT_TYPE APP)

include(./user.cmake OPTIONAL)
include(../common.cmake OPTIONAL)

include(OptionsCommon)
include(SetLibraryOutputName)
include(GroupSources) 

include(GuessCompilerPrefix)
GUESS_COMPILER_PREFIX(compiler_prefix)

list(APPEND CMAKE_PREFIX_PATH ${ASPOSE_CPPLIBS_ROOT})

# Defines "CodePorting.Native.Cs2Cpp" imported targets and find all dependencies
# Aspose::CodePorting.Native.Cs2Cpp - imported target with all dependencies
find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
include("${ASPOSE_EMAIL_CPP_ROOT}/Aspose.Email.Cpp-targets-${compiler_prefix}.cmake")

message(STATUS "Project name: ${PROJECT_NAME}")

file(GLOB_RECURSE srcs "source/*.cpp" "source/*.h")
file(GLOB_RECURSE hdrs "include/*.h")

# Additional global definitions

add_definitions(-DNET20)
add_definitions(-DNET_2_0)
add_definitions(-DNET_3_5)
add_definitions(-DNET_4_0)
add_definitions(-DNET_4_5)
add_definitions(-DINTERNAL)
add_definitions(-DLICENSED)
add_definitions(-DCPP_PORTING)
add_definitions(-DLICENSING_PROJECT)

# Define interface library for dependencies
add_library(${PROJECT_NAME}_dependencies INTERFACE)


# Dependencies
target_include_directories(${PROJECT_NAME}_dependencies INTERFACE 
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  
		${CMAKE_CURRENT_SOURCE_DIR}/source  )


target_link_libraries(${PROJECT_NAME}_dependencies INTERFACE Aspose.Email.Cpp)
target_link_libraries(${PROJECT_NAME}_dependencies INTERFACE Aspose::CodePorting.Native.Cs2Cpp)
target_link_libraries(${PROJECT_NAME}_dependencies INTERFACE CodePorting.Native.Cs2Cpp)

function(SetCommonTargetSettings target)
        target_link_libraries(${target} PUBLIC ${PROJECT_NAME}_dependencies PRIVATE ${CMAKE_DL_LIBS})
	
	if (DEFINED WORKING_DIR)
		set_target_properties(${target} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${WORKING_DIR}") 
	endif()

	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${target})
	
	if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set_property(TARGET ${target} APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-inconsistent-missing-override")
	endif()

	GroupSources(${target} "${CMAKE_CURRENT_SOURCE_DIR}")
	AsposeCommonTargetProperties(${target})
endfunction()

set(targets "")
set(COTIRE_PCH_MEMORY_SCALING_FACTOR "300")
include(cotire)
include(PrecompiledHeader)
include(AsposeNatvis)

set(target "${PROJECT_NAME}")
add_executable(${target} ${srcs} ${hdrs})
SetCommonTargetSettings(${target})
list(APPEND targets ${target})
target_compile_definitions(${target} PRIVATE "ASPOSE_EMAIL_EXAMPLES_SHARED_EXPORTS ${ASPOSECPP_NO_CHECKED_CASTS}")
AddAsposeNatvis(${target})

add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)      
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Native.Cs2Cpp>
        $<TARGET_FILE_DIR:${target}>)        
    
AddPrecompiledHeader("${targets}")

