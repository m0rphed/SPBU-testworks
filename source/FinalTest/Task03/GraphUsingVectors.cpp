#include "GraphUsingVectors.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Graph::exists(const int vertex)
{
    return this->vertices.count(vertex) != 0;
}

void Graph::addVertex(const int newVertex)
{
    this->vertices.insert({newVertex, this->edges.size()});
    this->edges.resize(this->edges.size() + 1);
}

void Graph::addEdge(const int vertexFrom, const int vertexTo, const int edgeLength)
{
    if (!exists(vertexFrom))
    {
        addVertex(vertexFrom);
    }

    if (!exists(vertexTo))
    {
        addVertex(vertexTo);
    }

    this->edges[this->vertices[vertexFrom]].push_back({vertexTo, edgeLength});
}

int Graph::getEdgeLength(int vertexFrom, int vertexTo)
{
    if (!exists(vertexFrom) || !exists(vertexTo))
    {
        return -1;
    }

    for (const pair<int, int> &current : this->edges[this->vertices[vertexFrom]])
    {
        if (current.first == vertexTo)
        {
            return current.second;
        }
    }

    return 0;
}

bool Graph::isAdjacent(const int vertexFrom, const int vertexTo)
{
    return this->getEdgeLength(vertexFrom, vertexTo) != 0;
}

vector<int> Graph::getAdjacentVertices(int vertex)
{
    vector<int> result;

    if (!exists(vertex))
    {
        return result;
    }

    for (const pair<int, int> &current : this->edges[this->vertices[vertex]])
    {
        result.push_back(current.first);
    }

    sort(result.begin(), result.end());
    return result;
}

int Graph::countVertices()
{
    return this->vertices.size();
}
