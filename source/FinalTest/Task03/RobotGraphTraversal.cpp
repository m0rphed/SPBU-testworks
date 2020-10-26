#include "RobotGraphTraversal.h"
#include "GraphUsingVectors.h"
#include "GraphBuildFromFile.h"
#include "DepthFirstSearch.h"
#include <stdexcept>
#include <unordered_set>
#include <iostream>
#include <locale>

// Дан граф в виде списка смежности.
//   В первой строке файла количество вершин графа,
//   в остальных строках для каждой вершины список смежных с ней вершин в формате
//   <количество смежных вершин> <список номеров вершин через пробел>.

//   В одной из вершин графа находится робот, который может путешествовать по вершинам, перепрыгивая через одну
//   (например, если граф имеет вид (1) — (2) — (3) и робот находися в вершине 1, он может попасть только в врешину 3).
//   Вывести все вершины, достижимые для робота. Вершина, в которой робот находится исходно, вводится с клавиатуры.

using namespace std;

void handleData(Graph *&myGraph, const string &fileName)
{
    ifstream data(fileName, ios::in);

    // Check that data can be found, and throw exception if it can not
    if (!data.is_open())
    {
        cerr << "ERROR: File not found." << endl;
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    auto matrix = buildMatrixFromFile(data);
    myGraph = buildGraphWithAdjacencyMatrix(matrix);

    data.close();
}

// Oh GOD, kill me pls
// it would be fair

void RobotTraversal(int startVertex)
{
    // print all robot comparable vertices
    auto myGraph = new Graph();
    handleData(myGraph, "data.txt");

    bool flag = true;
    unordered_set<int> result = jumpyDepthFirstSearch(myGraph, startVertex, flag);

    setlocale(LC_ALL, "Russian");
    cout << "\n\nРобот пойдёт по:" << endl;

    for (const auto &element : result)
    {
        cout << element << ", ";
    }

    cout << endl;
    delete myGraph;
}
