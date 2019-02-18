#include "pch.h"
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>
#include <boost/timer.hpp>

const int N = 10;

using namespace std;

void initVector(vector<size_t> &v, int n)
{
	for (int i = 0; i < n; i++)
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
	vector<size_t> v;
	initVector(v, N);
	copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
	cout << endl;
	getRandomPermutation(v);
	copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));

	/*do
	{
		//copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
	} while (std::next_permutation(v.begin(), v.end()));
	double duration = t.elapsed();
	copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
	std::cout << duration << std::endl;*/
	return 0;
}