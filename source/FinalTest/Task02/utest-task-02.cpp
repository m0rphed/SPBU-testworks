#include "./List.h"
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
    myList->printList();
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

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(expected[i], testList->getDataByPosition(i));
    }

    testList->printList();
    delete testList;
}
