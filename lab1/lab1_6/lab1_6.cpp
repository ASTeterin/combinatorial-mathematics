// lab1_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>
#include <boost/timer.hpp>

using namespace std;
const int N = 20;

void InitVector(vector<size_t> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v.push_back(0);
	}
}

void PrintSet(vector<size_t> &v, int n)
{
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		if (v[i] != 0)
		{
			cout << i << ' ';
		}
	}
	cout << '}' << '\n';
}

int main()
{
	boost::timer t;
	vector<size_t> v;
	int n = N;
	int i, j;
	j = 0;
	t.restart();
	InitVector(v, N);
	while (v[n] != 1)
	{
		//cout << j++ << ' ';
		PrintSet(v, n);
		i = 0;
		while (v[i] == 1)
		{
			v[i++] = 0;
			//i++;
		}
		v[i] = 1;
	}
	double duration = t.elapsed();
	std::cout << duration << std::endl;
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
