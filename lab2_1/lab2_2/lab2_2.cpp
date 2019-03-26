// lab2_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector < vector<int> > graph;
vector < vector<int> > transposedGraph;
vector<char> visited;
vector<int> order, component;

void InitVector(int n, vector<vector<int>> matrix)
{
	vector<int> row;
	row.assign(n, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		matrix.push_back(row);
	}
}

bool ReadData(istream &input, vector <vector<int>> &matrix, int &countVertex)
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
				continue;
			}
			currentRow >> weight;
			row.push_back(weight);
		}
		matrix.push_back(row);
		matrix.clear;
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
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
