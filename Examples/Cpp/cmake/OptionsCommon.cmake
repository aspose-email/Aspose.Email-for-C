# Enable C++14 support
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup using color in diagnostics for Ninja and if isn't jenkins job
# https://clang.llvm.org/docs/UsersManual.html#formatting-of-diagnostics
# https://gcc.gnu.org/onlinedocs/gcc-6.3.0/gcc/Diagnostic-Message-Formatting-Options.html
if (CMAKE_GENERATOR STREQUAL "Ninja" AND NOT DEFINED ENV{BUILD_ID})
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcolor-diagnostics")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND NOT MINGW)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdiagnostics-color")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
    endif()
endif()

# https://blogs.s-osg.org/an-introduction-to-accelerating-your-build-with-clang/
# https://blogs.s-osg.org/a-conclusion-to-accelerating-your-build-with-clang/

# Use ld.gold if it is available and isn't disabled explicitly
include(CMakeDependentOption)
CMAKE_DEPENDENT_OPTION(USE_LD_GOLD "Use GNU gold linker" ON "NOT WIN32;NOT APPLE" OFF)
if (USE_LD_GOLD)
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -fuse-ld=gold -Wl,--version ERROR_QUIET OUTPUT_VARIABLE LD_VERSION)
    if ("${LD_VERSION}" MATCHES "GNU gold")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
    else ()
        message(WARNING "GNU gold linker isn't available, using the default system linker.")
        set(USE_LD_GOLD OFF)
    endif ()
endif ()

set(ENABLE_DEBUG_FISSION_DEFAULT OFF)
if (USE_LD_GOLD AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(TestCXXAcceptsFlag)
    CHECK_CXX_ACCEPTS_FLAG(-gsplit-dwarf CXX_ACCEPTS_GSPLIT_DWARF)
    if (CXX_ACCEPTS_GSPLIT_DWARF)
        set(ENABLE_DEBUG_FISSION_DEFAULT ON)
    endif ()
endif ()

option(DEBUG_FISSION "Use Debug Fission support" ${ENABLE_DEBUG_FISSION_DEFAULT})
if (DEBUG_FISSION)
    if (NOT USE_LD_GOLD)
        message(FATAL_ERROR "Need GNU gold linker for Debug Fission support")
    endif ()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gdb-index")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--gdb-index")
endif ()

# TODO Add compiler sanitizers
# https://clang.llvm.org/docs/AddressSanitizer.html
# https://clang.llvm.org/docs/ThreadSanitizer.html
# https://clang.llvm.org/docs/MemorySanitizer.html
# https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
# https://clang.llvm.org/docs/DataFlowSanitizer.html
# https://clang.llvm.org/docs/LeakSanitizer.html

# Explicitly set a source charset to UTF8 https://goo.gl/zWGRC9
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

# Suppress noisy warnings, work with big object files 
if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ignore:4099 /ignore:4098 /ignore:4221")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /ignore:4099 /ignore:4098 /ignore:4221") 
endif()

# Generate partial PDB
# https://blogs.msdn.microsoft.com/vcblog/2015/10/16/debugfastlink-for-vs2015-update-1/
if (USE_FASTLINK AND MSVC)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /debug:fastlink")
endif()

# Enable build with Multiple Processes - https://msdn.microsoft.com/en-us/library/bb385193.aspx
# This option is required only for MSBuild
if (MSVC AND CMAKE_GENERATOR MATCHES "^Visual Studio")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()

if (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# Solve issue with as.exe fatal error - Object file has too many sections
# http://stackoverflow.com/a/28372660
if (MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif()

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /wd4250 /wd4723")
endif()

if (MSVC_OPTIMIZATION AND MSVC)
    # /GF - String pooling
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GF")

    # /Oy - Enable frame pointer omission (FPO) (otherwise CMake will automatically turn it off)
    # /Gy - Function-level linking
    # /GL - Link time code generation (whole program optimization)
    # Asposecpp doesn't compile with /GL
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Oy /Gy")

    # /DYNAMICBASE - Address space load randomization (ASLR)
    # /NXCOMPAT - Data execution prevention (DEP)
    # /LARGEADDRESSAWARE - >2GB user address space on x86
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DYNAMICBASE /NXCOMPAT /LARGEADDRESSAWARE")

    # /OPT:REF /OPT:ICF - Fold out duplicate code at link step
    # /INCREMENTAL:NO - Required to use /LTCG
    # /LTCG - Link time code generation (whole program optimization)
    # Asposecpp doesn't compile with /LTCG
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /OPT:REF /OPT:ICF /INCREMENTAL:NO")
endif()

# https://docs.microsoft.com/en-us/cpp/build/reference/how-to-debug-a-release-build?view=vs-2017
if (PDB_FOR_RELEASE AND MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG")
    if (NOT MSVC_OPTIMIZATION)
        set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /OPT:REF /OPT:ICF /INCREMENTAL:NO")
    endif()
endif()

if (USE_DUCIBLE AND MSVC)
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /INCREMENTAL:NO")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")
endif()

function(AsposeCommonTargetProperties target)
    if (DEBUG_FISSION)
        set_property(TARGET ${target} APPEND_STRING PROPERTY COMPILE_FLAGS " -gsplit-dwarf")
    endif()
endfunction()

function(TreatWarningsAsErrors)
    if (MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /W4 /experimental:external /external:W0 /external:env:INCLUDE /external:env:CAExcludePath /external:templates- /wd4435 /wd4820 /wd4625 /wd5026 /wd4626 /wd5027 /wd4263 /wd4264 /wd4266 /wd4514 /wd4571 /wd4100 /wd4623 /wd4061 /wd4063 /wd4127 /wd4193 /wd4706 /wd4458 /wd4459 /wd4189 /wd4702 /wd4103 /wd4121" PARENT_SCOPE)
        # TODO: replace /wd4623 with /external:wd4623 once the syntax is supported
        
        # The following warnings are suspended:
        # C4435: 'class1' : Object layout under /vd2 will change due to virtual base 'class2'. - Noisy, reports every virtual inheritance, which is unlikely to be unintended.
        # C4820: 'bytes' bytes padding added after construct 'member_name'. - Reports all gaps between data members. To fix them in library, there's CSPORTCPP-2770 raised. In ported code these are unlikely to be fixed.
        # C4625: 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted. - Reports too many library special classes, noisy for ported code.
        # C5026: 'type': move constructor was implicitly defined as deleted. - Unpredictably noisy for ported code.
        # C4626: 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted. - Nothing useful.
        # C5027: 'type': move assignment operator was implicitly defined as deleted. - Not useful.
        # C4263: 'function' : member function does not override any base class virtual member function. - In ported code and library classes, it's normal situation.
        # C4264: C4264 is always generated after C4263. - Nothing useful, but annoying.
        # C4266: 'function' : no override available for virtual member function from base 'type'; function is hidden. - Yes, porter is to generate explicit 'using' in this case.
        # C4514: 'function' : unreferenced inline function has been removed. - Requires every inline function from any header to be used in each compilation unit which is nonsense.
        # C4571: Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught. - Not useful for us from any perspective.
        # C4100: 'identifier' : unreferenced formal parameter. - Sometimes is useful, but uncontrollable for ported code, and doesn't recognize functions throwing NotImplementedException, thus too noisy.
        # C4623: 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted. - Nothing useful.
        # C4061: enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label. - Too noisy for ported code.
        # C4063: case 'identifier' is not a valid value for switch of enum 'enumeration'. - Triggers for bitmasks.
        # C4127: conditional expression is constant. - False alarms for constexpr- or template argument-based conditions.
        # C4193: #pragma warning(pop): no matching '#pragma warning(push)', - Reports some library headers, not fixed with /external:W0.
        # C4706: assignment within conditional expression. - Not suspended even by valid syntax like '!!(ns = *nsList)'.
        # C4458: declaration of 'identifier' hides class member. - Normal situation for ported code.
        # C4459: declaration of 'identifier' hides global declaration. - Normal situation.
        # C4189: 'identifier' : local variable is initialized but not referenced. - For ported code, there's same warning generated in C# already.
        # C4702: unreachable code. - Triggers for closing braces after 'throw' statements.
        # C4103: 'filename' : alignment changed after including header, may be due to missing #pragma pack(pop). - Generated for library headers, not fixed by /external:W0.
        # C4121: 'symbol' : alignment of a member was sensitive to packing. - Generated for ported code, where we don't reorder fields.
        
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /WX" PARENT_SCOPE)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /WX" PARENT_SCOPE)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror" PARENT_SCOPE)
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror" PARENT_SCOPE)
    endif()
endfunction()
