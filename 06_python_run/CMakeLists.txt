set(SOURCE_FILES main.cpp)

add_executable(python_run ${SOURCE_FILES})
target_link_libraries(python_run ${PYTHON_LIBRARIES})
set_target_properties(python_run PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")
