#include "DepthFirstSearch.h"

using namespace std;

void depthSearch(Graph *graph, const int vertex, unordered_set<int> &visited)
{
    for (int current : graph->getAdjacentVertices(vertex))
    {
        if (visited.count(current) == 0)
        {
            visited.insert(current);
            depthSearch(graph, current, visited);
        }
    }
}

void depthSearchWithFlag(Graph *graph, const int vertex, bool flag, unordered_set<int> &visited)
{
    for (int current : graph->getAdjacentVertices(vertex))
    {
        if (visited.count(current) == 0)
        {
            if (flag)
            {
                visited.insert(current);
            }
            depthSearchWithFlag(graph, current, !flag, visited);
        }
    }
}

unordered_set<int> depthFirstSearch(Graph *graph, const int vertex)
{
    unordered_set<int> visited;
    visited.insert(vertex);
    depthSearch(graph, vertex, visited);
    return visited;
}

unordered_set<int> jumpyDepthFirstSearch(Graph *graph, int vertex, bool flag)
{
    unordered_set<int> visited;
    visited.insert(vertex);
    depthSearchWithFlag(graph, vertex, flag, visited);
    return visited;
}
