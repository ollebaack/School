#include <iostream>
#include "Statistic.h"
#include "dataLog.h"
#include "Test.h"
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace Tenttt;
using namespace Tent;
using namespace Tentt;
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
const int N = 10000;


int min_r(array<int, N> &a, int start)
{

	if (start == a.size() - 1)
	{
		return a[start];
	}
	double smal = min_r(a, start + 1);
	if (a[start] < smal) {
		return a[start];
	}
	else
		return smal;
}
int min_i(array<int, N> &a)
{
	int min = a[0];   // 5 8 2 0 1
	for (int i = a.size() - 1; i > 0; i--)
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
	//Upg 3-3.1
	//fill_array(a);
	//cout << min_r(a, 0) << endl;
	//cout << min_i(a);

	//Upg 3.2

	//Statistic stat;
	//stat.Readfromfile();
	////stat.list();
	////stat.searchip();
	//stat.print();
	//cout << "Meanvalue: " << stat.calculate_mean() << endl;

	//Upg 3.3
	//dataLog dl;

	/*dl.Readfromfile();	
	dl.print();*/

	

	system("PAUSE");
	return 0;

}