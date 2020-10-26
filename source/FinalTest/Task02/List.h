#pragma once

#include <iostream>

using namespace std;

typedef int ElementType;

struct Node
{
    ElementType data;
    Node *next;

    Node();

    explicit Node(const ElementType &value);
};

//------------------------------------------LINKED-LIST--------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
class LinkedList
{
private:
    Node *head;
    int length;

    // Destroys list recursively
    void destroyList();

public:
    // Default constructor
    LinkedList();

    // Constructor can make a list from array of ElementType
    LinkedList(const ElementType *arrayOfElements, const int &arrayLength);

    // Default destructor
    ~LinkedList();

    // Func. to iterate through the list and get the real length of the list
    int countNodes();

    // Getter-function for length
    int getLength();

    // Getter-function for head
    Node *getHead();

    // Shifts linked list, insert new element at the position of head
    void shift(const ElementType &value); // changes length

    // Inserts element, doesn't break the order of the items in the list
    void sortedInsert(const ElementType &data); // changes length

    // Inserts new element
    void insertElement(const ElementType &data);

    // Returns data of element on position
    ElementType getDataByPosition(const int &position);

    // Deletes element with value = <data>
    void deleteElement(const ElementType &data); // changes length

    // Returns pointer to element on position
    Node *getElementByPosition(const int &position);

    void reverse();

    // Prints the whole list
    void printList();

    // Handles dialog interface
    void linkedListInterface();
};
