#pragma once
#include <fstream>

// Сотворяет граф
bool **createGraph(int size);

void depthFirstSearch(bool **graph, int size, bool **visited, int counter, int number);

void printAdjacencyMatrix(bool **graph, int size);

void destroyGraph(bool **graph, int size);

int **readIncMatrix(std::ifstream &file, int size, int roads);

bool **fromIncToAdjMatrix(int **incMatrix, int size, int roads, bool **graph);
