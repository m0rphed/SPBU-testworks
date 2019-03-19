#pragma once

#include <vector>
#include <unordered_map>

struct Graph
{
	unsigned int verticesAmount = 0;
	std::vector<std::vector<int>> edges;
	std::unordered_map<int, int> vertices;
};


// create new graph and get pointer to it
Graph *newGraph();

// checks a vertex for existence in the graph
bool exists(Graph *graph, int vertex);

// add a vertex to the graph
void addVertex(Graph *graph, int vertex);

// add an edge between two vertices of the graph
void addEdge(Graph *graph, int vertexFrom, int vertexTo, int newLength);

// get vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, int vertex);

// check if one vertex is adjacent to another
bool isAdjacent(Graph *graph, int vertexFrom, int vertexTo);

// get length of an edge
int edgeLength(Graph *graph, int vertexFrom, int vertexTo);

// deletes graph completely
void deleteGraph(Graph *&graph);

// returns amount of vertices
unsigned int verticesAmount(Graph *graph);

