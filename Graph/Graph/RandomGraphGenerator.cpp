#include "stdafx.h"

#include "RandomGraphGenerator.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace graphs;

void RandomGraphGenerator::GenerateGraph(int const &vertices, int const &edges)
{
	fstream outputFile("topsort.in", fstream::trunc | fstream::out);
	outputFile.trunc;

	outputFile << vertices << " " << edges << '\n';

	for (int i = 1; i <= vertices; i++)
	{
		for (int j = i + 1; j <= vertices; j++)
		{
			outputFile << i << " " << j << '\n';
		}
	}

	outputFile.close();
}