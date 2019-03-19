cmake_minimum_required(VERSION 3.12)

# Define helper functions & structures
set(HELPERS Graph/graph.cpp
            Graph/depthFirstSearch.cpp)

# Define all homework files
set(TASKS_SRCS  task-03.cpp)

# Define all tests
#set(TESTS   utest-task-01.cpp)

add_executable(Task03 ${TASKS_SRCS} ${HELPERS} main.cpp)
#target_link_libraries(Task03 gmock gtest gtest_main pthread)
