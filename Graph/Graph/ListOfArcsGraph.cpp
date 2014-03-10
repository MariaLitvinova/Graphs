#include "stdafx.h"
#include "ListOfArcsGraph.h"

using namespace std;
using namespace graphs;

ListOfArcsGraph::ListOfArcsGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph)
{
	numberOfEdges = numberOfEdgesInGraph;
	numberOfVertices = numberOfVerticesInGraph;

	for (int i = 0; i < numberOfEdges; i++)
	{
		matrixOfArcs[i][0] = -1;
		matrixOfArcs[i][1] = -1;
	}

	for (int i = 0; i < numberOfVertices; i++)
	{
		numberOfArcsFromI[i] = 0;
		numberOfArcsToI[i] = 0;
	}
}

void ListOfArcsGraph::AddEdge(int startVertex, int endVertex, int weight)
{
	matrixOfArcs[currentEdgeNumber][0] = startVertex;
	matrixOfArcs[currentEdgeNumber][1] = endVertex;

	currentEdgeNumber++;

	arcsFromI[startVertex].push_back(endVertex);
	arcsToI[endVertex].push_back(startVertex);

	numberOfArcsFromI[startVertex]++;
	numberOfArcsToI[endVertex]++;
}

void ListOfArcsGraph::RemoveEdge(int startVertex, int endVertex)
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (matrixOfArcs[i][0] == startVertex
			&&
			matrixOfArcs[i][1] == endVertex)
		{
			matrixOfArcs[i][0] = -1;
			matrixOfArcs[i][1] = -1;

			numberOfArcsFromI[startVertex]--;
			numberOfArcsToI[endVertex]--;
		}

		currentEdgeNumber--;
	}
}

void ListOfArcsGraph::PrintGraph()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		cout << matrixOfArcs[i][0] << " " << matrixOfArcs[i][1] << '\n';
	}
}

bool ListOfArcsGraph::WayExists(int startVertex, int endVertex)
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (matrixOfArcs[i][0] == startVertex
			&&
			matrixOfArcs[i][1] == endVertex)
		{
			return true;
		}
	}
	return false;
}

list<int> ListOfArcsGraph::IncomingTo(int vertex)
{
	list<int> incoming;

	if (numberOfArcsToI[vertex] == 0)
	{
		return incoming;
	}

	for (int i = 0; i < numberOfEdges; i++)
	{
		if (matrixOfArcs[i][1] == vertex)
		{
			incoming.push_back(matrixOfArcs[i][0]);
		}
	}

	return incoming;
}

list<int> ListOfArcsGraph::OutcomingFrom(int vertex)
{
	list <int> outcoming;

	if (numberOfArcsFromI[vertex] == 0)
	{
		return outcoming;
	}
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (matrixOfArcs[i][0] == vertex)
		{
			outcoming.push_back(matrixOfArcs[i][1]);
		}
	}

	return outcoming;
}

list<int> ListOfArcsGraph::VerticesWithNoIncomingEdges()
{
	list<int> noIncoming;

	set<int> allVertices;

	for (int i = 0; i < numberOfVertices; i++)
	{
		if (numberOfArcsToI[i] == 0)
		{
			noIncoming.push_back(i);
		}
	}

	return noIncoming;
}

bool ListOfArcsGraph::GraphHasEdges()
{
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (matrixOfArcs[i][0] > -1
			&&
			matrixOfArcs[i][1] > -1)
		{
			return true;
		}
	}

	return false;
}

int ListOfArcsGraph::NumberOfEdges()
{
	return numberOfEdges;
}

int ListOfArcsGraph::NumberOfVertices()
{
	return numberOfVertices;
}