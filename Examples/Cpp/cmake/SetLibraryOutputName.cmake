# Add prefix to ouput library name

function(SetLibraryOutputName target)
    include(GuessCompilerPrefix)
    GUESS_COMPILER_PREFIX(_SUFFIX)
    
    get_target_property(_name ${target} NAME)
    string(TOLOWER "${_name}" _name)
	
	if (_name STREQUAL "codeporting.native.cs2cpp")
		set(_name "cpp")
	endif()
    
    set_target_properties(${target} PROPERTIES 
        OUTPUT_NAME "aspose_${_name}_${_SUFFIX}"
        DEBUG_POSTFIX "d"
        PROJECT_LABEL "aspose_${_name}")

    get_target_property(_output_name ${target} OUTPUT_NAME)
    message(STATUS "Output name: '" ${_output_name} "'")
endfunction()

function(SetPortedLibraryOutputName target)
    include(GuessCompilerPrefix)
    GUESS_COMPILER_PREFIX(_SUFFIX)
    
    get_target_property(_name ${target} NAME)
    
    set_target_properties(${target} PROPERTIES 
        OUTPUT_NAME "${_name}_${_SUFFIX}"
        DEBUG_POSTFIX "d")

    get_target_property(_output_name ${target} OUTPUT_NAME)
    message(STATUS "Output name: '" ${_output_name} "'")
endfunction()
