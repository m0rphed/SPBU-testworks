// Ориентированный граф задаётся матрицей смежности
// Найти все циклы в графе или вывести,
// что их нет, оценить асимптотику

#include "task-03.h"

using namespace std;

void depthSearchToFindCycles(Graph *graph, int vertex, unordered_set<int> &visited, vector<int> &cycles,
                             map<int, string> &colors)
{
	colors[vertex] = "grey";
	for (int current : adjacent(graph, vertex))
	{
		if (colors[current] == "none")
		{
			visited.insert(current);
			depthSearchToFindCycles(graph, current, visited, cycles, colors);
		}

		if (colors[current] == "grey")
		{
			cycles.push_back(current);
		}

		colors[vertex] = "black";
	}
}

pair<unordered_set<int>, vector<int>>
depthFirstSearchToFindCycles(Graph *graph, int vertex, vector<int> cycles, const int &verticesCount)
{
	unordered_set<int> visited;
	map<int, string> colors;

	for (int i = 0; i < verticesCount; ++i)
	{
		colors[i] = "none";
	}

	visited.insert(vertex);
	depthSearchToFindCycles(graph, vertex, visited, cycles, colors);

	return make_pair(visited, cycles);
}
