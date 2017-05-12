set(SOURCE_FILES custom.cpp)
set(MODULE_NAME custom)

add_library(extending_python MODULE ${SOURCE_FILES})
target_link_libraries (extending_python LINK_PUBLIC ${PYTHON_LIBRARIES})

set_target_properties(extending_python PROPERTIES PREFIX "")
set_target_properties(extending_python PROPERTIES OUTPUT_NAME "${MODULE_NAME}")
set_target_properties(extending_python PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")