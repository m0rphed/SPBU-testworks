#pragma once

struct List;
struct Node;

//returns pointer to the new list
List *newList();

//deletes list completely
void deleteList(List *&list);

// inserts a new element to the beginning of the list
void insert(List *list, int value);

//inserts an element after another element
bool insertNext(List *list, int value, int previousPosition);

//removes the first element
bool removeHead(List *list);

//removes an element after another element
bool removeNext(List *list, int previousPosition);

//returns pointer to the node on particular position
Node *findNode(const List *list, int position);

//checks if the list is empty 
bool isEmpty(const List *list);

//returns value of the node
int value(const Node *targetNode);

//returns pointer to the first element
Node *head(const List *list);

//returns pointer to the next element after current
Node *next(const Node *previousNode);

