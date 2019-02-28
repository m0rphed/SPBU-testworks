cmake_minimum_required(VERSION 3.12)
project(spbu-testworks)

# Set C++11 standart
set(CMAKE_CXX_STANDARD 11)

enable_testing()

# Let's CONFIGURE GTEST
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

# Locate solutions for FinalTest-01
add_subdirectory(source/FinalTest/Task01)

# Locate solutions for FinalTest-02
add_subdirectory(source/FinalTest/Task02)

# Locate solutions for FinalTest-03
add_subdirectory(source/FinalTest/Task03)

set(SOURCE_FILES init_gtest.cpp)
add_executable(spbuTestWorks ${SOURCE_FILES})

# Link current run-configuration with what we want to test and the GTest and pthread library
target_link_libraries(spbuTestWorks gmock gtest_main pthread)
