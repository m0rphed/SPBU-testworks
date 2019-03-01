#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

bool **createGraph(const int size)
{
    bool **myGraph = new bool *[size];
    for (int i = 0; i < size; i++)
    {
        myGraph[i] = new bool[size];
        for (int j = 0; j < size; j++)
        {
            myGraph[i][j] = false;
        }
    }
    return myGraph;
}


void destroyGraph(bool **graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}


void depthFirstSearch(bool **graph, int size, bool **visited, int counter, int number)
{
    visited[counter][number] = true;
    for (int i = 0; i <= size; i++)
    {
        if ((graph[number][i] != 0) && (!visited[counter][i]))
        {
            depthFirstSearch(graph, size, visited, counter, i);
        }
    }
}


int **readIncMatrix(ifstream &file, int size, int roads)
{
    int **matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[roads];
        for (int j = 0; j < roads; j++)
        {
            file >> matrix[i][j];
        }
    }
    return matrix;
}


void printAdjacencyMatrix(bool **graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            cout << graph[i][k] << " ";
        }
        cout << endl;
    }
}


bool **fromIncToAdjMatrix(int **incMatrix, int size, int roads, bool **graph)
{
    for (int column = 0; column < roads; column++)
    {
        int from = -1;
        int to = -1;
        for (int row = 0; row < size && (from == -1 || to == -1); row++)
        {
            if (incMatrix[row][column] == 1)
            {
                from = row;
            }
            else if (incMatrix[row][column] == -1)
            {
                to = row;
            }
        }
        if (from >= 0 && to >= 0)
        {
            graph[from][to] = true;
        }
    }
    return graph;
}