#include "stdafx.h"

#include "MatrixOfAdjacencyGraph.h"

using namespace std;
using namespace graphs;

int const infinity = 100000000000000000;

MatrixOfAdjacencyGraph::MatrixOfAdjacencyGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph)
{
	numberOfEdges = numberOfEdgesInGraph;
	numberOfVertices = numberOfVerticesInGraph;

	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			matrixOfAdjacency[i][j] = infinity;
		}
	}
}

void MatrixOfAdjacencyGraph::AddEdge(int startVertex, int endVertex, int weight)
{
	matrixOfAdjacency[startVertex][endVertex] = weight;

	matrixOfOutcomingVertices[startVertex].push_front(endVertex);
	matrixOfIncomingVertices[endVertex].push_front(startVertex);
}

void MatrixOfAdjacencyGraph::RemoveEdge(int startVertex, int endVertex)
{
	matrixOfAdjacency[startVertex][endVertex] = infinity;

	matrixOfOutcomingVertices[startVertex].remove(endVertex);
	matrixOfIncomingVertices[endVertex].remove(startVertex);
}

void MatrixOfAdjacencyGraph::PrintGraph()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			cout << matrixOfAdjacency[i][j] << " ";
		}
		cout << "\n";
	}
}

bool MatrixOfAdjacencyGraph::WayExists(int startVertex, int endVertex)
{
	return matrixOfAdjacency[startVertex][endVertex] != infinity;
}

int MatrixOfAdjacencyGraph::WayCost(int startVertex, int endVertex)
{
	return matrixOfAdjacency[startVertex][endVertex];
}

list<int> MatrixOfAdjacencyGraph::IncomingTo(int vertex)
{
	list<int> incoming = matrixOfIncomingVertices[vertex];
	return incoming;
}

list<int> MatrixOfAdjacencyGraph::OutcomingFrom(int vertex)
{
	list<int> outcoming = matrixOfOutcomingVertices[vertex];
	return outcoming;
}

int MatrixOfAdjacencyGraph::NumberOfEdges()
{
	return numberOfEdges;
}

int MatrixOfAdjacencyGraph::NumberOfVertices()
{
	return numberOfVertices;
}