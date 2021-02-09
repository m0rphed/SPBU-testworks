#include "graph.h"

using namespace std;

Graph *newGraph()
{
	return new Graph;
}

bool exists(Graph *graph, const int vertex)
{
	return graph->vertices.count(vertex) != 0;
}

void addVertex(Graph *graph, const int vertex)
{
	if (exists(graph, vertex))
	{
		return;
	}

	graph->vertices.insert({vertex, graph->verticesAmount});
	++graph->verticesAmount;
	graph->edges.resize(graph->verticesAmount);

	for (int i = 0; i < graph->verticesAmount; ++i)
	{
		graph->edges[i].resize(graph->verticesAmount);
	}
}

void addEdge(Graph *graph, const int vertexFrom, const int vertexTo, const int newLength)
{
	if (!exists(graph, vertexFrom))
	{
		addVertex(graph, vertexFrom);
	}

	if (!exists(graph, vertexTo))
	{
		addVertex(graph, vertexTo);
	}

	graph->edges[graph->vertices[vertexFrom]][graph->vertices[vertexTo]] = newLength;
}

vector<int> adjacent(Graph *graph, const int vertex)
{
	vector<int> adjacentNodes;

	if (graph->vertices.count(vertex) == 0)
	{
		return adjacentNodes;
	}

	for (auto &current : graph->vertices)
	{
		if (graph->edges[graph->vertices[vertex]][current.second] != 0)
		{
			adjacentNodes.push_back(current.first);
		}
	}

	return adjacentNodes;
}

bool isAdjacent(Graph *graph, const int vertexFrom, const int vertexTo)
{
	if (!exists(graph, vertexFrom) || !exists(graph, vertexTo))
	{
		return false;
	}

	return graph->edges[graph->vertices[vertexFrom]][graph->vertices[vertexTo]] != 0;
}

int edgeLength(Graph *graph, const int vertexFrom, const int vertexTo)
{
	if ((graph->vertices.count(vertexFrom) == 0) || (graph->vertices.count(vertexTo) == 0))
	{
		return 0;
	}

	return graph->edges[graph->vertices[vertexFrom]][graph->vertices[vertexTo]];
}

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}

unsigned int verticesAmount(Graph *graph)
{
	return graph->verticesAmount;
}