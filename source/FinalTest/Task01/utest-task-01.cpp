#include "./task-01.h"
#include <vector>
#include <gtest/gtest.h> // Google Test Framework

TEST(finalTest_task_01, countDigitTest)
{
    ASSERT_EQ(13, countSumOfDigits(12145));
    ASSERT_EQ(13, countSumOfDigits(-12145));
}

TEST(finalTest_task_01, allElementsHaveSameSum)
{
    const int length = 7;
    int counter = 0;
    long testArray[] = {3, 12, 21, 30, 102, 120, 201};

    std::vector<long> result = findAllNumbers(testArray, length);

    for (auto &element : result)
    {
        ASSERT_EQ(element, testArray[counter]);
        ++counter;
    }

    printResult(result);
}

TEST(finalTest_task_01, simpleTest)
{
    const int length = 10;
    int counter = 0;
    long testArray[] = {3, 20, -10, 11, 12, 21, 30, 102, 120, 201};
    std::vector<long> expected = {3, 12, 21, 30, 102, 120, 201};
    std::vector<long> result = findAllNumbers(testArray, length);

    ASSERT_EQ(expected, result);
    printResult(result);
}