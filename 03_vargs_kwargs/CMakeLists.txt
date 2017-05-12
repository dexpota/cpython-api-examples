set(SOURCE_FILES custom.cpp)
set(MODULE_NAME custom)

add_library(vargs_kwargs MODULE ${SOURCE_FILES})
target_link_libraries (vargs_kwargs LINK_PUBLIC ${PYTHON_LIBRARIES})

set_target_properties(vargs_kwargs PROPERTIES PREFIX "")
set_target_properties(vargs_kwargs PROPERTIES OUTPUT_NAME "${MODULE_NAME}")
set_target_properties(vargs_kwargs PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python")