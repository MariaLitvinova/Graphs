// Graph.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <exception>

#include "AbstractGraph.h"
#include "ListOfArcsGraph.h"
#include "IncidenceMatrixGraph.h"
#include "GraphUtils.h"
#include "MatrixOfAdjacencyGraph.h"
#include "RandomGraphGenerator.h"

using namespace std;
using namespace graphs;

void InitializeNonweightedGraph(
	AbstractGraph *graph
	, fstream &inputFile)
{
	int startVertex = 0;
	int endVertex = 0;

	int numberOfEdges = graph->NumberOfEdges();

	for (int i = 0; i < numberOfEdges; i++)
	{
		inputFile >> startVertex;
		inputFile >> endVertex;

		graph->AddEdge(startVertex - 1, endVertex - 1);
	}
}

void InitializeWeightedGraph(
	AbstractGraph *graph
	, fstream &inputFile)
{
	int startVertex = 0;
	int endVertex = 0;
	int weight = 0;

	int numberOfEdges = graph->NumberOfEdges();

	for (int i = 0; i < numberOfEdges; i++)
	{
		inputFile >> startVertex;
		inputFile >> endVertex;
		inputFile >> weight;

		graph->AddEdge(startVertex - 1, endVertex - 1, weight);
	}
}

list<int> KannAlgorythm(
	AbstractGraph *graph
	, fstream &inputFile)
{
	list<int> sortedVertices;

	list<int> verticesWithNoIncoming = graph->VerticesWithNoIncomingEdges();

	if (verticesWithNoIncoming.empty())
	{
		sortedVertices.push_back(-1);
	}
	else
	{
		sortedVertices = GraphUtils::KannAlgorythm(verticesWithNoIncoming, graph);
	}

	return sortedVertices;
}

list<int> DfsAlgorythm(
	AbstractGraph *graph
	, fstream &inputFile)
{
	int numberOfVertices = graph->NumberOfVertices();

	bool isCyclic = false;
	list<int> sortedVertices = GraphUtils::BasedOnDfsAlgorythm(graph, isCyclic);

	if (isCyclic)
	{
		sortedVertices.clear();
		sortedVertices.push_back(-1);
	}

	return sortedVertices;
}

int main()
{
	fstream inputFile;
	inputFile.open("topsort.in");

	int numberOfVertices = 0;
	int numberOfEdges = 0;

	inputFile >> numberOfVertices;
	inputFile >> numberOfEdges;

	IncidenceMatrixGraph *graph = new IncidenceMatrixGraph(numberOfVertices, numberOfEdges);
	InitializeNonweightedGraph(graph, inputFile);

	graph->PrintGraph();

	return 0;
}
