#include <iostream>
#include <fstream>
#include "Graph.h"
#include <locale>
using namespace std;

void makeGraphFromFile()
{
    string fileName = "data.txt";
    ifstream data(fileName, ios::in);

    // Check that data can be found, and throw exception if it can not
    if (!data.is_open())
    {
        cerr << "ERROR: File not found." << endl;
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    int size = 0;
    data >> size;

    int roads = 0;
    data >> roads;

    int **matrix = readIncMatrix(data, size, roads);

    data.close();

    bool **graph = createGraph(size);
    graph = fromIncToAdjMatrix(matrix, size, roads, graph);

    printAdjacencyMatrix(graph, size);

    bool **visited = createGraph(size);
    for (int i = 0; i < size; i++)
    {
        depthFirstSearch(graph, size, visited, i, i);
    }

    for (int k = 0; k < size; k++)
    {
        bool flag = true;
        for (int l = 0; l < size; l++)
        {
            if (!visited[l][k])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << k << endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    destroyGraph(visited, size);
    destroyGraph(graph, size);
}
