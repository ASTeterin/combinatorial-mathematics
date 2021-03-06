// lab1_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>
#include <boost/timer.hpp>

using namespace std;
const int N = 20;
const int K = 5;

void InitVector(vector<int> &v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
}


int main()
{
	vector<int> v;
	int m = 1;
	InitVector(v, K);
	v.insert(v.begin(), -1);
	boost::timer t;
	t.restart();
	int j = 0;
	while (m != 0)
	{
		copy(v.begin() + 1, v.end(), ostream_iterator<int>(cout, " "));
		cout << '\n';
		m = K;
		while (v[m] == N - K + m)
		{
			m--;
		}
		v[m]++;
		for (int i = m + 1; i < K; i++)
		{
			v[i] = v[i - 1] + 1;
		}
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
