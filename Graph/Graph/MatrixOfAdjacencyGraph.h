#pragma once

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "AbstractGraph.h"

namespace graphs {

	/// this graph s weighted

	class MatrixOfAdjacencyGraph : public AbstractGraph
	{
	public:
		MatrixOfAdjacencyGraph(int const &numberOfEdgesInGraph, int const &numberOfVerticesInGraph);

		void AddEdge(int startVertex, int endVertex, int weight);
		void RemoveEdge(int startVertex, int endVertex);

		void PrintGraph();

		bool WayExists(int startVertex, int endVertex);
		int WayCost(int startVertex, int endVertex);

		std::list<int> IncomingTo(int vertex);
		std::list<int> OutcomingFrom(int vertex);

		std::list<int> VerticesWithNoIncomingEdges() {
			return std::list<int>();
		};

		int NumberOfEdges();
		int NumberOfVertices();

		bool GraphHasEdges() { return false; };

	private:
		long int matrixOfAdjacency[2000][2000];
		std::list<int> matrixOfOutcomingVertices[2000];
		std::list<int> matrixOfIncomingVertices[2000];

		int numberOfVertices;
		int numberOfEdges;

		int current;
	};
}