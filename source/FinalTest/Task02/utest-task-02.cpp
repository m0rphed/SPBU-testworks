#include "./List.h"
#include "./InsertionSort.h"

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

    delete testList;
}