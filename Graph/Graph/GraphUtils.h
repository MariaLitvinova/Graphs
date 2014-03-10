#pragma once

#include "stdafx.h"
#include <list>
#include <set>
#include <vector>

#include "AbstractGraph.h"

namespace graphs {

	class GraphUtils
	{
	public:
		static std::list<int> KannAlgorythm(std::list<int> verticesWithNoIncoming, AbstractGraph *graph);

		static std::list<int> BasedOnDfsAlgorythm(AbstractGraph *graph, bool &isCyclic);

		static std::list<int> Cutpoints(AbstractGraph *graph, int const &numberOfEdges);

		static std::list<int> Step(int const &initialVertex, AbstractGraph *graph);

	private:
		static void visit(
			int vertex
			, AbstractGraph *graph
			, std::list<int> *unmarked
			, std::set<int> temporarilyMarked
			, std::list<int> *sortedVertices
			, bool &isCyclic
			);

		static void Dfs(int const &vertex, bool visited[], AbstractGraph *graph, std::list<int> *result);

		static void ModifiedDfsWithTimer(
			int const &vertex
			, int const &parent
			, bool visited[]
			, AbstractGraph *graph
			, std::list<int> *result
			, int timer
			, int entranceTime[]
			, int updateTime[]
			);
	};
}