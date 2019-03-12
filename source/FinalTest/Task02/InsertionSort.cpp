#include "InsertionSort.h"

void insertionSort(LinkedList *&list)
{
    // Initialize sorted linked list
    auto *sorted = new LinkedList();

    // copy head to current
    auto *currentNode = list->getHead();

    while (currentNode)
    {
        // Store next for next iteration
        auto *next = currentNode->next;

        // insert current in sorted linked list
        sorted->sortedInsert(currentNode->data);

        // Update current
        currentNode = next;
    }

    // Delete old list
    delete list;

    // Update pointer
    list = sorted;
}
