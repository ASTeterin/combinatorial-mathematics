// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <clocale>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>     


using namespace std;
ifstream fin;
int countVertex;

typedef vector<vector<int>>  Matrix;

void InitMatrix(Matrix &matrix, int countVertex)
{
	vector<int> currentRow(countVertex, 0);
	for (int row = 0; row < countVertex; row++)
	{
		matrix.push_back(currentRow);
	}
}


void ReadData(Matrix &graph)
{
	string s;
	int lineNum = 0;
	int countEdge;
	int vertex1;
	int vertex2;
	while (getline(fin, s))
	{
		istringstream fullLine(s);
		if (lineNum == 0)
		{
			fullLine >> countVertex >> countEdge;
			InitMatrix(graph, countVertex);
		}
		else
		{
			fullLine >> vertex1 >> vertex2;
			graph[vertex1 - 1][vertex2 - 1] = 1;
			graph[vertex2 - 1][vertex1 - 1] = 1;
		}
		lineNum++;
		
	}
}


bool openInputFile(string inputFile)
{
	fin.open(inputFile, ios::in);
	if (!fin.is_open())
	{
		cout << "Не удается открыть входной файл\n";
		return false;
	}
	return true;
}


void PrintGraph(Matrix const& graph, int countVertex)
{
	for (int i = 0; i < countVertex; i++)
	{
		copy(graph[i].begin(), graph[i].end(), std::ostream_iterator<size_t>(std::cout, " "));
		cout << "\n";
	}
}

vector<int> tIn, tOut;
vector<bool> visited;
int timer = 0;

struct edge {
	int vertex1;
	int vertex2;
};

vector<edge> bridges;
vector<int> articulationPoint;


void DFS(Matrix const& graph, int currentVertex, int parrentVertex = -1) 
{
	visited[currentVertex] = true;
	tIn[currentVertex] = tOut[currentVertex] = timer++;
	int children = 0;
	for (int i = 0; i < countVertex; ++i)
	{
		if (graph[currentVertex][i] == 1)
		{
			int nextVertex = i;
			if (nextVertex == parrentVertex)  continue;

			if (visited[nextVertex])
			{
				tOut[currentVertex] = std::min(tOut[currentVertex], tIn[nextVertex]);
			}
			else
			{
				DFS(graph, nextVertex, currentVertex);
				tOut[currentVertex] = std::min(tOut[currentVertex], tOut[nextVertex]);
				if (tOut[nextVertex] > tIn[currentVertex])
				{
					edge currEdge = { currentVertex, nextVertex };
					bridges.push_back(currEdge);
				}
			}
		}
	}
}

void PrintResult(vector<edge> const& bridge, vector<int> &articulationPoint)
{
	cout << "Bridges in graph" << '\n';
	for (int i = 0; i < bridge.size(); i++)
	{
		cout << bridge[i].vertex1 + 1 << " " << bridge[i].vertex2 + 1 << '\n';
	}
	cout << "points" << '\n';
	copy(articulationPoint.begin(), articulationPoint.end(), std::ostream_iterator<int>(std::cout, " "));
}

void FindBridges(Matrix const& graph)
{
	timer = 0;
	visited.resize(countVertex);
	tIn.resize(countVertex);
	tOut.resize(countVertex);
	for (int i = 0; i < countVertex; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < countVertex; ++i)
	{
		if (!visited[i])
		{
			DFS(graph, i);
		}
	}
}

void FindArticulationPoint(Matrix const& graph, vector<edge> const& bridges, vector<int> &articulationPoint)
{
	for (edge element : bridges)
	{
		if (std::accumulate(graph[element.vertex1].begin(), graph[element.vertex1].end(), 0) > 1)
		{
			if (std::find(articulationPoint.begin(), articulationPoint.end(), element.vertex1 + 1) == articulationPoint.end())
			{
				articulationPoint.push_back(element.vertex1 + 1);
			}
		}
		if (std::accumulate(graph[element.vertex2].begin(), graph[element.vertex2].end(), 0) > 1)
		{
			if (std::find(articulationPoint.begin(), articulationPoint.end(), element.vertex2 + 1) == articulationPoint.end())
			{
				articulationPoint.push_back(element.vertex2 + 1);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	Matrix graph;
	if (argc != 2)
	{
		cout << "Invalid arguments count. Use the program call format lab2.cpp <input_file>\n";
		return 1;

	}
	//string fileName = argv[1];
	openInputFile(argv[1]);
	ReadData(graph);
	FindBridges(graph);
	FindArticulationPoint(graph, bridges, articulationPoint);
	PrintResult(bridges, articulationPoint);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for GettIng Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add ExistIng Item to add existIng code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
