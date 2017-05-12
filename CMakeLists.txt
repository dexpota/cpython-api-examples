cmake_minimum_required(VERSION 3.6)
project(cpython)

set(CMAKE_CXX_STANDARD 11)

if(APPLE)
    find_program(PYTHON_CONFIG_EXECUTABLE python-config)
    if (NOT PYTHON_CONFIG_EXECUTABLE)
        message(SEND_ERROR "python-config executable not found, but python is required.")
    endif()
    # using "python-config --prefix" so that cmake always uses the python that is
    # in the user's path, this is a fix for homebrew on Mac:
    # https://github.com/Homebrew/homebrew/issues/25118 [^]
    execute_process(COMMAND ${PYTHON_CONFIG_EXECUTABLE} --prefix OUTPUT_VARIABLE python_prefix OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(PYTHON_INCLUDE_DIR ${python_prefix}/include/python2.7)
    set(PYTHON_LIBRARY ${python_prefix}/lib/libpython2.7${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(00_extending_python)
add_subdirectory(01_errors_exceptions)
add_subdirectory(02_callback)
add_subdirectory(03_vargs_kwargs)
add_subdirectory(04_custom_type)
add_subdirectory(05_python_function_call)