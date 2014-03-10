#include "stdafx.h"
#include "GraphUtils.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using namespace graphs;

list<int> GraphUtils::KannAlgorythm(std::list<int> verticesWithNoIncoming, AbstractGraph *graph)
{
	list<int> sortedVertices;

	while (!verticesWithNoIncoming.empty())
	{
		int currentVertex = verticesWithNoIncoming.front();
		verticesWithNoIncoming.pop_front();

		sortedVertices.push_back(currentVertex);

		list<int> outcoming = graph->OutcomingFrom(currentVertex);
		for each (int outcomingVertex in outcoming)
		{
			graph->RemoveEdge(currentVertex, outcomingVertex);
			if (graph->IncomingTo(outcomingVertex).empty())
			{
				verticesWithNoIncoming.push_back(outcomingVertex);
			}
		}
	}

	return sortedVertices;
}

list<int> GraphUtils::BasedOnDfsAlgorythm(AbstractGraph *graph, bool &isCyclic)
{
	list<int> sortedVertices;
	list<int> unmarked;

	int const numberOfVertices = graph->NumberOfVertices();
	for (int i = 0; i < numberOfVertices; i++)
	{
		unmarked.push_back(i);
	}

	set<int> temporarilyMarked;

	while (!unmarked.empty())
	{
		int currentVertex = unmarked.front();

		visit(currentVertex, graph, &unmarked, temporarilyMarked, &sortedVertices, isCyclic);
	}

	return sortedVertices;
}

list<int> GraphUtils::Cutpoints(AbstractGraph *graph, const int &numberOfEdges)
{
	int timeOfEntrance[20000];
	int update[20000];

	bool visited[20000];

	for (int i = 0; i < 20000; i++)
	{
		timeOfEntrance[i] = -1;
		update[i] = -1;

		visited[i] = false;
	}

	int timer = 0;

	list<int> result;

	ModifiedDfsWithTimer(0, -1, visited, graph, &result, timer, timeOfEntrance, update);

	while (!result.empty())
	{
		cout << result.front() << " ";
		result.pop_front();
	}

	return result;
}

list<int> GraphUtils::Step(int const &initialVertex, AbstractGraph *graph)
{
	list<int> dfsResult;

	bool visited[20000];

	for (int i = 0; i < 20000; i++)
	{
		visited[i] = false;
	}

	visited[initialVertex] = true;
	dfsResult.push_back(initialVertex);
	Dfs(initialVertex, visited, graph, &dfsResult);

	return dfsResult;
}

void GraphUtils::visit(
	int vertex
	, AbstractGraph *graph
	, list<int> *unmarked
	, set<int> temporarilyMarked
	, list<int> *sortedVertices
	, bool &isCyclic
	)
{
	if (temporarilyMarked.find(vertex) != temporarilyMarked.end())
	{
		isCyclic = true;
		return;
	}

	list<int>::iterator iter = find(unmarked->begin(), unmarked->end(), vertex);
	if (iter != unmarked->end())
	{
		temporarilyMarked.insert(vertex);

		list<int> outcoming = graph->OutcomingFrom(vertex);
		for each (int outcomingVertex in outcoming)
		{
			visit(outcomingVertex
				, graph
				, unmarked
				, temporarilyMarked
				, sortedVertices
				, isCyclic
				);
		}

		temporarilyMarked.erase(vertex);
		unmarked->remove(vertex);
		sortedVertices->push_front(vertex);
	}
}

void GraphUtils::Dfs(int const &vertex, bool visited[], AbstractGraph *graph, list<int>* result)
{
	visited[vertex] = true;
	result->push_back(vertex);

	list<int> outcoming = graph->OutcomingFrom(vertex);

	if (!outcoming.empty())
	{
		for each (int curVertex in outcoming)
		{
			if (!visited[curVertex])
			{
				Dfs(curVertex, visited, graph, result);
				result->push_back(curVertex);
				result->push_back(vertex);
			}
		}
	}
}

void GraphUtils::ModifiedDfsWithTimer(
	int const &vertex
	, int const &parent
	, bool visited[]
	, AbstractGraph *graph
	, list<int> *result
	, int timer
	, int entranceTime[]
	, int updateTime[]
	)
{
	timer++;
	entranceTime[vertex] = timer;
	updateTime[vertex] = timer;
	visited[vertex] = true;

	list<int> outcoming = graph->OutcomingFrom(vertex);

	int children = 0;
	if (!outcoming.empty())
	{
		for each (int curVertex in outcoming)
		{
			if (!visited[curVertex])
			{
				if (curVertex != parent) {
					ModifiedDfsWithTimer(curVertex, vertex, visited, graph, result, timer, entranceTime, updateTime);
					updateTime[vertex] = min(updateTime[vertex], updateTime[curVertex]);
					if ((updateTime[curVertex] >= entranceTime[vertex]) && parent != -1)
					{
						result->push_back(vertex);
					}
					children++;
				}
			}
			else
			{
				updateTime[vertex] = min(updateTime[vertex], entranceTime[curVertex]);
			}
		}
	}
	if (parent == -1 && children > 1)
	{
		result->push_back(vertex);
	}
}