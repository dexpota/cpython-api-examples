set(SOURCE_FILES main.cpp)

add_executable(python_function_call ${SOURCE_FILES})
target_link_libraries(python_function_call ${PYTHON_LIBRARIES})
set_target_properties(python_function_call PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")
