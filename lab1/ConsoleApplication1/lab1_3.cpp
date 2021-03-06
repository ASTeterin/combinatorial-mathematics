#include "pch.h"
#include <conio.h> 
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>
#include <boost/timer.hpp>

const int N = 10;

using namespace std;

void initVector(vector<size_t> &v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
}

void getRandomPermutation(vector<size_t> &v)
{
	int n = v.size();
	int j;
	for (int i = 0; i < n - 1; i++)
	{
		j = rand() % n;
		swap(v[i], v[j]);
	}
}



int main()
{
	srand(time(NULL));
	vector<size_t> v;
	initVector(v, N);
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
	cout << endl;
	getRandomPermutation(v);
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
	return 0;
}