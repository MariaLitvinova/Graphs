#pragma once

#include "stdafx.h"

#include <list>

namespace graphs {

	class AbstractGraph
	{
	public:
		virtual void AddEdge(int startVertex, int endVertex, int weight = 1) = 0;
		virtual void RemoveEdge(int startVertex, int endVertex) = 0;

		virtual void PrintGraph() = 0;

		virtual bool WayExists(int startVertex, int endVertex) = 0;
		virtual int WayCost(int startVertex, int endVertex) = 0;

		virtual std::list<int> IncomingTo(int vertex) = 0;
		virtual std::list<int> OutcomingFrom(int vertex) = 0;

		virtual std::list<int> VerticesWithNoIncomingEdges() = 0;

		virtual int NumberOfEdges() = 0;
		virtual int NumberOfVertices() = 0;

		virtual bool GraphHasEdges() = 0;
	};
}