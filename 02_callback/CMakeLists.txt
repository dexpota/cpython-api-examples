set(SOURCE_FILES custom.cpp)
set(MODULE_NAME custom)

add_library(callback MODULE ${SOURCE_FILES})
target_link_libraries (callback LINK_PUBLIC ${PYTHON_LIBRARIES})

set_target_properties(callback PROPERTIES PREFIX "")
set_target_properties(callback PROPERTIES OUTPUT_NAME "${MODULE_NAME}")
set_target_properties(callback PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")