#pragma once

#include "GraphUsingVectors.h"
#include <vector>
#include <fstream>

// Reads matrix from file as vector
std::vector<std::vector<int>> buildMatrixFromFile(std::ifstream &inputFile);

// Builds graph using adjacency matrix
Graph *buildGraphWithAdjacencyMatrix(const std::vector<std::vector<int>> &matrix);
