cmake_minimum_required(VERSION 3.12)

# Define all using data structures source files
set(DataStructures  GraphUsingVectors.cpp
                    GraphBuildFromFile.cpp
                    DepthFirstSearch.cpp)

# Define all sorce files
set(TaskSrcs RobotGraphTraversal.cpp)

# Define all tests
set(Tests utest-task-03.cpp)

add_executable(Task03 ${TaskSrcs} ${Tests} ${DataStructures})
target_link_libraries(Task03 gmock gtest gtest_main pthread)