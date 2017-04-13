#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <random>
#include <array>

array<int, 10000> a;
array<int, 10> b;
default_random_engine dre;
uniform_int_distribution<int> uid1(0, 1000000);

template<size_t SIZE>
void fill_array(array<int, SIZE> &a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = uid1(dre);
	}
}
const int N = 10;


//int recursive_mean(array<int, N> &a, int start)
//{
//	if (start = N - 1)
//	{
//		return a[start];
//	}
//
//	else
//	{
//		int sum = 0;
//		if (recursive_mean(a, start + 1) > 0)
//		{
//			sum = a[start] + recursive_mean(a, start + 1);
//		}
//		return sum;
//	}
//}

int rekarray(array<int, N> &a, int start)
{
	// 9 1 2 5 2 0
	if (start == a.size() - 1)
	{
		return a[start];
	}
	double smal = rekarray(a, start + 1);
	if (a[start] < smal) {
		return a[start];
	}
	else
		return smal;
}
int loopmega(array<int, N> &a)
{
	int min = a[0];   // 5 8 2 0 1
	for (int i = a.size()-1; i > 0; i--)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}


int main()
{

	fill_array(b);
	cout << rekarray(b, 0) << endl;
	cout << loopmega(b);





	system("PAUSE");
	return 0;

}