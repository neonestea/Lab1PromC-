project(array_test)

set(ARRAY_TEST_SRC_FILES
    src/test.cpp
)

add_executable(array_test ${ARRAY_TEST_SRC_FILES} ${CMAKE_SOURCE_DIR}/third-party/Catch2/extras/catch_amalgamated.cpp)
target_include_directories(array_test PRIVATE ${CMAKE_SOURCE_DIR}/third-party/Catch2/src)

set_target_properties(array_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)