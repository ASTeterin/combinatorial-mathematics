// lab1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>
#include <boost/timer.hpp>

using namespace std;
const int N = 15;

void InitVector(vector<size_t> &v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
}

void InitIdenticalVector(vector<int> &v, int n, int value)
{
	for (int i = 1; i <= n ; i++)
	{
		v.push_back(value);
	}
}

int main()
{
	vector<size_t> pi, p;
	vector<int> d;
	int m;
	InitVector(pi, N);
	InitVector(p, N);
	InitIdenticalVector(d, N, -1);
	d[0] = 0;
	pi.insert(pi.begin(), N + 1);
	p.insert(p.begin(), N + 1);
	pi.push_back(N + 1);
	m = N;
	boost::timer t;
	t.restart();

	while (m != 1)
	{
		//copy(pi.begin(), pi.end(), ostream_iterator<size_t>(cout, " "));
		//cout << '\n';
		m = N;
		while (pi[p[m] + d[m-1]] > m)
		{
			d[m-1] *= -1;
			m--;
		}
		swap(pi[p[m]], pi[p[m] + d[m-1]]);
		swap(p[pi[p[m]]], p[m]);
	}
	double duration = t.elapsed();
	std::cout << duration << std::endl;
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
