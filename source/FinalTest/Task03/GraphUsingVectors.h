#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

class Graph
{
    std::vector<std::vector<std::pair<int, int>>> edges;
    std::unordered_map<int, size_t> vertices;

public:
    // Default constructor: creates new graph
    Graph() = default;

    // Default destructor: deletes new graph
    ~Graph() = default;

    // Checks if a vertex exists in the graph
    bool exists(int vertex);

    // Adds a new vertex to the graph
    void addVertex(int newVertex);

    // Adds a new edge to the graph
    void addEdge(int vertexFrom, int vertexTo, int edgeLength);

    // Returns the length of an edge
    int getEdgeLength(int vertexFrom, int vertexTo);

    // Checks if one vertex is adjacent to another
    bool isAdjacent(int vertexFrom, int vertexTo);

    // Returns the vector of adjacent vertices
    std::vector<int> getAdjacentVertices(int vertex);

    // Returns amount of vertices
    int countVertices();
};