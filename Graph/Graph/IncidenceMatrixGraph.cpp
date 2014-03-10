#include "stdafx.h"

#include "IncidenceMatrixGraph.h"

using namespace std;
using namespace graphs;

IncidenceMatrixGraph::IncidenceMatrixGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph)
{
	numberOfEdges = numberOfEdgesInGraph;
	numberOfVertices = numberOfVerticesInGraph;

	currentNumberOfEdges = numberOfEdgesInGraph;

	for (int i = 0; i < numberOfVertices; i++)
	{
		matrixOfIncoming[i] = new list<int>();
		matrixOfOutcoming[i] = new list<int>();
	}
}

void IncidenceMatrixGraph::AddEdge(int startVertex, int endVertex, int weight)
{
	matrixOfOutcoming[startVertex]->push_back(endVertex);
	matrixOfIncoming[endVertex]->push_back(startVertex);
}

void IncidenceMatrixGraph::RemoveEdge(int startVertex, int endVertex)
{
	matrixOfOutcoming[startVertex]->remove(endVertex);
	matrixOfIncoming[endVertex]->remove(startVertex);

	currentNumberOfEdges--;
}

void IncidenceMatrixGraph::PrintGraph()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		list<int> curList = *matrixOfOutcoming[i];
		cout << "vertex: " << i << ", points to: ";
		for (auto it = curList.begin(); it != curList.cend(); ++it)
		{
			cout << ' ' << *it;
		}
		cout << '\n';
	}
}

list<int> IncidenceMatrixGraph::IncomingTo(int vertex)
{
	list<int> incoming = *matrixOfIncoming[vertex];
	return incoming;
}

list<int> IncidenceMatrixGraph::OutcomingFrom(int vertex)
{
	list<int> outcoming = *matrixOfOutcoming[vertex];
	return outcoming;
}

list<int> IncidenceMatrixGraph::VerticesWithNoIncomingEdges()
{
	list<int> withNoIncomingEdges;

	for (int i = 0; i < numberOfVertices; i++)
	{
		if (IncomingTo(i).empty())
		{
			withNoIncomingEdges.push_back(i);
		}
	}

	return withNoIncomingEdges;
}

bool IncidenceMatrixGraph::GraphHasEdges()
{
	return (currentNumberOfEdges == 0);
}

int IncidenceMatrixGraph::NumberOfEdges()
{
	return numberOfEdges;
}

int IncidenceMatrixGraph::NumberOfVertices()
{
	return numberOfVertices;
}