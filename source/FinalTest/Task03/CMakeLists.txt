cmake_minimum_required(VERSION 3.12)

# Define helper functions
#set(HELPERS ../helpers/arrayHelpers.cpp)

# Define all homework files
set(TASKS_SRCS  task-03-2.cpp
                graph.cpp)

# Define all tests
set(TESTS   utest-task-03-2.cpp)

add_executable(Task03 ${TASKS_SRCS} ${TESTS})
target_link_libraries(Task03 gmock gtest gtest_main pthread)
