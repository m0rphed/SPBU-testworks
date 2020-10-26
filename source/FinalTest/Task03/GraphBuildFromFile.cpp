#include "GraphBuildFromFile.h"

using namespace std;

vector<vector<int>> buildMatrixFromFile(ifstream &inputFile)
{
    vector<vector<int>> result;

    unsigned int matrixHeight = 0;
    unsigned int matrixWidth = 0;

    inputFile >> matrixHeight;
    inputFile >> matrixWidth;

    result.resize(matrixHeight);

    for (int i = 0; i < matrixHeight; ++i)
    {
        result[i].resize(matrixWidth);

        for (int j = 0; j < matrixWidth; ++j)
        {
            int value = 0;
            inputFile >> value;
            result[i][j] = value;
        }
    }

    return result;
}

Graph *buildGraphWithAdjacencyMatrix(const vector<vector<int>> &matrix)
{
    auto *result = new Graph();

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            const int length = matrix[i][j];
            if (length != 0)
            {
                result->addEdge(i, j, matrix[i][j]);
            }
        }
    }

    return result;
}
