#pragma once
#include "Graph/depthFirstSearch.h"
#include "Graph/graph.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <utility>

void depthSearchToFindCycles(Graph *graph, int vertex, std::unordered_set<int> &visited, std::vector<int> &cycles,
                             std::map<int, std::string> &colors);

std::pair<std::unordered_set<int>, std::vector<int>> depthFirstSearchToFindCycles(Graph *graph, int vertex,
                                                                                  std::vector<int> cycles,
                                                                                  const int &verticesCount);
