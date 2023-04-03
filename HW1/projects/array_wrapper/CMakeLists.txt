project(array_wrapper)

set(ARRAY_WRAPPER_SRC_FILES
    src/array_wrapper.cpp
)

add_executable(array_wrapper ${ARRAY_WRAPPER_SRC_FILES})

set_target_properties(array_wrapper PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)