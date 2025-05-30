# Add your test source file(s) here
add_executable(c_logger_test c_logger_test.c)

# Add the include directory for c-logger headers
target_include_directories(c_logger_test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../c-logger)
target_sources(c_logger_test
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../c-logger/c-logger.c
)

# Link with the logger library if it's built as a library
# target_link_libraries(c_logger_test PRIVATE c-logger)

# Register the test with CTest
add_test(NAME c_logger_test COMMAND c_logger_test)