set(SOURCE_FILES custom.cpp)
set(MODULE_NAME custom)

add_library(errors_exceptions MODULE ${SOURCE_FILES})
target_link_libraries (errors_exceptions LINK_PUBLIC ${PYTHON_LIBRARIES})

set_target_properties(errors_exceptions PROPERTIES PREFIX "")
set_target_properties(errors_exceptions PROPERTIES OUTPUT_NAME "${MODULE_NAME}")
set_target_properties(errors_exceptions PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")