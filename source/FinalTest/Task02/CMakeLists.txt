cmake_minimum_required(VERSION 3.12)

# Define helper functions
#set(HELPERS ../helpers/arrayHelpers.cpp)

# Define all homework files
set(TASKS_SRCS  task-02.cpp
        )

# Define all tests
set(TESTS       utest-task-02.cpp)

add_executable(Task02 ${TASKS_SRCS} ${TESTS})
target_link_libraries(Task02 gmock gtest gtest_main pthread)
