cmake_minimum_required(VERSION 3.12)

# Define helper functions
#set(HELPERS ../helpers/arrayHelpers.cpp)

# Define all homework files
set(TASKS_SRCS  task-01.cpp)

# Define all tests
set(TESTS   utest-task-01.cpp)

add_executable(Task01 ${TASKS_SRCS} ${TESTS})
target_link_libraries(Task01 gmock gtest gtest_main pthread)
