set(SOURCE_FILES custom.cpp)
set(MODULE_NAME custom)

add_library(custom_type MODULE ${SOURCE_FILES})
target_link_libraries (custom_type LINK_PUBLIC ${PYTHON_LIBRARIES})

set_target_properties(custom_type PROPERTIES PREFIX "")
set_target_properties(custom_type PROPERTIES OUTPUT_NAME "${MODULE_NAME}")
set_target_properties(custom_type PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")