#include "task-01.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <locale>

using namespace std;

unsigned countSumOfDigits(long number)
{
    number = abs(number);
    unsigned sum = 0;

    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

unsigned findMaxSum(long *array, const int &length)
{
    unsigned max = 0;
    for (int i = 0; i < length; ++i)
    {
        unsigned temp = countSumOfDigits(array[i]);
        if (temp > max)
        {
            max = temp;
        }
    }

    return max;
}

std::vector<long> findAllNumbers(long *input, const int &length)
{
    vector<long> result;

    unsigned maxSum = findMaxSum(input, length);

    for (int i = 0; i < length; ++i)
    {
        if (countSumOfDigits(input[i]) == maxSum)
        {
            result.push_back(input[i]);
        }
    }

    return result;
}

void printResult(std::vector<long> &numbers)
{
    setlocale(LC_ALL, "Russian");
    cout << "\nЧисла с максимальной суммой цифр:" << std::endl;
    for (auto &element : numbers)
    {
        cout << element << ", ";
    }

    cout << endl;
}
