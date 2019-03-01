#include "task-03-2.h"
#include <gtest/gtest.h> // Google Test Framework
#include <locale>

TEST(finalTest_task_03, duckTest) // this rest trying to pretend he do some important shit
{
    setlocale(LC_ALL, "Russian");
    makeGraphFromFile();
    SUCCEED();
}