#include "List.h"

// Function to sort a singly linked list using insertion sort
void insertionSort(LinkedList *list)
{
    // Initialize sorted linked list 
    auto *sorted = new Node;

    // Traverse the given linked list and insert every 
    // node to sorted 
    auto *current = list->getDataByPosition(0);
    while (current != nullptr)
    {
        // Store next for next iteration 
        struct Node *next = current->next;

        // insert current in sorted linked list 
        sortedInsert(&sorted, current);

        // Update current 
        current = next;
    }

    // Update head_ref to point to sorted linked list 
    *list = sorted;
}

/* function to insert a new_node in a list. Note that this 
  function expects a pointer to head_ref as this can modify the 
  head of the input linked list (similar to push())*/
void sortedInsert(struct Node **head_ref, struct Node *new_node)
{
    struct Node *current;
    /* Special case for the head end */
    if (*head_ref == nullptr || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next != nullptr &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
} 