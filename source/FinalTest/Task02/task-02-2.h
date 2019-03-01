#include <string>
#include <iostream>

struct Node
{
    std::string Name;
    int loyalty = 0;
    Node *next = nullptr;
};

void insertNode(Node *&list, int &listSize, const std::string &secondName, int const loyalty);

void sortByLoyalty(Node *list, int const listSize);

void sortBySecondName(Node *list, int const listSize);

void printList(Node *list, int const listSize);

void StalinInterface(int killCount = 0, int sendCount = 0);