#pragma once

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "AbstractGraph.h"

namespace graphs {

	/// This graph is non-weighted

	class IncidenceMatrixGraph : public AbstractGraph
	{
	public:
		IncidenceMatrixGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph);

		void AddEdge(int startVertex, int endVertex, int weight = 1);
		void RemoveEdge(int startVertex, int endVertex);

		void PrintGraph();

		bool WayExists(int startVertex, int endVertex) { return false; };
		int WayCost(int startVertex, int endVertex) { return 1; };

		std::list<int> IncomingTo(int vertex);
		std::list<int> OutcomingFrom(int vertex);

		std::list<int> VerticesWithNoIncomingEdges();

		int NumberOfEdges();
		int NumberOfVertices();

		bool GraphHasEdges();

	private:
		std::list<int>* matrixOfOutcoming[100000];
		std::list<int>* matrixOfIncoming[100000];

		int numberOfEdges;
		int numberOfVertices;

		int currentNumberOfEdges;
	};
}