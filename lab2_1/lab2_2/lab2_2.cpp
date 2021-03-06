// lab2_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>     

using namespace std;

vector < vector<int> > graph;
vector < vector<int> > transposedGraph;
vector<char> visited;
vector<int> order, component;

void InitVector(vector<vector<int>> &matrix, int n)
{
	vector<int> row;
	row.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		matrix.push_back(row);
	}
}

void ReadData(istream &input, vector <vector<int>> &matrix, int &countVertex)
{
	bool isFirsRow = true;
	int weight;
	string rowString;
	vector <int> row;
	while (getline(input, rowString))
	{
		istringstream currentRow(rowString);
		while (currentRow)
		{
			if (isFirsRow)
			{
				currentRow >> countVertex;
				isFirsRow = false;
				break;
			}
			currentRow >> weight;
			row.push_back(weight);
		}
		if (!row.empty())
		{
			matrix.push_back(row);
			row.clear();
		}
	}
}

vector <vector<int>> TransposedMatrix(vector <vector<int>> &matrix, int n)
{
	vector <vector<int>> transposedMatrix;
	InitVector(transposedMatrix, n);
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			transposedMatrix[col][row] = matrix[row][col];
		}
	}
	return transposedMatrix;
}

void DfsAndSort(vector <vector<int>> const& matrix, int vertex, vector<bool> &visited, vector<int> &topSort)
{
	visited[vertex] = true;
	for (int i = 0; i < visited.size(); ++i)
	{
		int weight = matrix[vertex][i];
		if ((weight != 0) && (!visited[i]))
		{
			DfsAndSort(matrix, i, visited, topSort);
		}
		
	}
	topSort.push_back(vertex);
}

void FindSCC(vector<vector<int>> const& matrix, int vertex, vector<bool> &visited)
{
	visited[vertex] = true;
	for (int i = 0; i < matrix[vertex].size(); ++i)
	{
		int weight = matrix[vertex][i];
		if ((weight != 0) && (!visited[i]))
		{
			FindSCC(matrix, i, visited);
		}
			
	}


			
}

bool CheckFile(ifstream &input)
{
	if (!input.is_open())
	{
		cout << "Failed to open matrix\n";
		return false;
	}
	return true;
}

bool ParseCommandLine(int argc, char* argv[], string &fileName)
{
	if (argc != 2)
	{
		cout << "Invalid count of argument";
		return false;
	}
	fileName = argv[1];
	return true;
}

int main(int argc, char* argv[])
{
	vector<vector<int>> matrix;
	vector<vector<int>> trMatrix;
	vector<bool> visited;
	vector<int> topSortVertex;
	int countVertex;
	int countSCC = 0;
	string fileName;

	if (!ParseCommandLine(argc, argv, fileName))
	{
		return 1;
	}

	ifstream input(fileName);
	if (!CheckFile(input))
	{
		return 1;
	}

	ReadData(input, matrix, countVertex);
	trMatrix = TransposedMatrix(matrix, countVertex);

	visited.assign(countVertex, false);
	for (int i = 0; i < countVertex; ++i)
	{
		if (!visited[i])
		{
			DfsAndSort(matrix, i, visited, topSortVertex);
		}
	}

	visited.assign(countVertex, false);

	for (int i = 0; i < countVertex; ++i)
	{
		int vertex = topSortVertex[countVertex - 1 - i];
		if (!visited[vertex])
		{
			FindSCC(trMatrix, vertex, visited);
			countSCC++;
		}
	}

	(countSCC == 1) ? cout << "YES" : cout << "NO";
		
		

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
