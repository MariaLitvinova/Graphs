#pragma once

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <list>
#include <set>

#include "AbstractGraph.h"

namespace graphs {

	/// This graph is non-weighted

	class ListOfArcsGraph : public AbstractGraph
	{
	public:

		ListOfArcsGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph);

		void AddEdge(int startVertex, int endVertex, int weight = 1);
		void RemoveEdge(int startVertex, int endVertex);

		void PrintGraph();

		bool WayExists(int startVertex, int endVertex);
		int WayCost(int startVertex, int endVertex) { return 1; };

		std::list<int> IncomingTo(int vertex);
		std::list<int> OutcomingFrom(int vertex);

		std::list<int> VerticesWithNoIncomingEdges();

		int NumberOfEdges();
		int NumberOfVertices();

		bool GraphHasEdges();

	private:

		int matrixOfArcs[100000][2];

		std::list<int> arcsFromI[100000];
		std::list<int> arcsToI[100000];

		int numberOfArcsFromI[100000];
		int numberOfArcsToI[100000];

		int numberOfEdges;
		int numberOfVertices;

		int currentEdgeNumber = 0;
	};
}