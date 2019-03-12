#include "./List.h"
#include "./InsertionSort.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <gtest/gtest.h> // Google Test Framework

TEST(linkedListTests, fromArrayToList)
{
    auto *arrayOfElements = new ElementType[10];
    for (int i = 0; i < 10; ++i)
    {
        arrayOfElements[i] = i;
    }

    auto *myList = new LinkedList(arrayOfElements, 10);
    //myList->printList();
    delete myList;
}

TEST(linkedListTests, simpleTest)
{
    auto *expected = new ElementType[10];
    for (int i = 0; i < 10; ++i)
    {
        expected[i] = i;
    }

    auto *testList = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        testList->insertElement(i);
    }

    //testList->printList();

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(expected[i], testList->getDataByPosition(i));
    }

    testList->printList();

    // destructor will be called
    delete testList;
}

TEST(insertionSort, simpleSorting)
{
    auto *expected = new ElementType[10];
    for (int i = 0; i < 10; ++i)
    {
        expected[i] = i;
    }

    auto *testList = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        testList->insertElement(i);
    }

    // Будет: 9 8 7 6 5 4 3 2 1 0
    testList->reverse();

    cout << "\nReversed: ";
    testList->printList();
    cout << endl;

    insertionSort(testList);

    cout << "Sorted: ";
    testList->printList();
    cout << endl;

    ASSERT_EQ(10, testList->getLength());
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(expected[i], testList->getDataByPosition(i));
    }

    delete testList;
}

TEST(insertionSort, randomTest)
{
    const int length = 10;
    auto *random = new ElementType[length];

    /* initialize random seed: */
    srand(time(nullptr));

    for (int i = 0; i < 10; ++i)
    {
        /* generate secret number between 1 and 10: */
        random[i] = rand() % 100 + 1;
    }

    // insert whole array in list using special test constructor
    auto *testList = new LinkedList(random, length);

    cout << "\nBefore sorting: ";
    testList->printList();
    cout << endl;

    insertionSort(testList);

    cout << "Sorted: ";
    testList->printList();
    cout << endl;

    ASSERT_EQ(length, testList->getLength());

    ElementType lastElement = testList->getHead()->data;

    for (int i = 0; i < length; ++i)
    {
        if (lastElement > testList->getDataByPosition(i))
        {
            FAIL();
        }

        lastElement = testList->getDataByPosition(i);
    }

    delete testList;
}