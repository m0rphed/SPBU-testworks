#pragma once

#include "GraphUsingVectors.h"
#include <unordered_set>

// Returns set of vertices visited during depth-first-search
std::unordered_set<int> depthFirstSearch(Graph *graph, int vertex);

// Returns set of vertices visited during jumpy-depth-first-search
std::unordered_set<int> jumpyDepthFirstSearch(Graph *graph, int vertex, bool flag);