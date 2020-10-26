cmake_minimum_required(VERSION 3.12)

# Define all using data structures source files
set(DataStructures List.cpp)

# Define all sorce files
set(TaskSrcs InsertionSort.cpp)

# Define all tests
set(Tests utest-task-02.cpp)

add_executable(Task02 ${TaskSrcs} ${Tests} ${DataStructures})
target_link_libraries(Task02 gmock gtest gtest_main pthread)
