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
#include <iterator>     // std::ostream_iterator



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


void PrintGraph(Matrix graph, int countVertex)
{

	for (int i = 0; i < countVertex; i++)
	{
		copy(graph[i].begin(), graph[i].end(), std::ostream_iterator<size_t>(std::cout, " "));
		cout << "\n";
	}
}

vector<int> tin, fup;
vector<bool> visited;
int timer = 0;
struct edge {
	int vertex1;
	int vertex2;
};

vector<edge> ed;
vector<int> cp;


void DFS(Matrix graph, int currentVertex, int parrentVertex = -1) // poisk v glubinu
{
	visited[currentVertex] = true;
	tin[currentVertex] = fup[currentVertex] = timer++;
	int children = 0;
	for (int i = 0; i < countVertex; ++i)
	{
		if (graph[currentVertex][i] == 1)
		{
			int nextVertex = i;
			if (nextVertex == parrentVertex)  continue;

			if (visited[nextVertex])
			{
				fup[currentVertex] = std::min(fup[currentVertex], tin[nextVertex]);
			}
			else
			{
				DFS(graph, nextVertex, currentVertex);
				fup[currentVertex] = std::min(fup[currentVertex], fup[nextVertex]);
				if (fup[nextVertex] > tin[currentVertex])
				{
					//std::cout << "bridge: (" << currentVertex + 1 << " , " << nextVertex + 1 << ")\n";
					edge e = { currentVertex, nextVertex };
					ed.push_back(e);
					if (parrentVertex != -1)
					{
						cp.push_back(currentVertex);
					}
					children++;
				}
			}
		}
	}
	if ((parrentVertex == -1) && (children > 1))
	{
		cp.push_back(currentVertex);
	}

}

void FindBridges(Matrix graph) // poisk mostov
{
	timer = 0;
	visited.resize(countVertex);
	tin.resize(countVertex);
	fup.resize(countVertex);
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

int main()
{
	Matrix graph;
	openInputFile("d:\\graph.txt");
	ReadData(graph);
	FindBridges(graph);
	//PrintGraph(graph, 14);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
