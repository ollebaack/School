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


long rfac(long n)
{
	volatile long r = 0;

	if (n == 0)
	{
		r = 1;       //Sätt brytpunkten här för att nå ner till basfallet och uppnystning
		//_asm { mov[sp_value_end], esp }
	}
	else
		r = n*rfac(n - 1);

	return r;       //Brytpunkt med CONDITION: n==0
}

float rek(int n, float x)
{
	float n1 = 0;
	//int x;

	if (n < 0)
		return 0;

	else
		n1 = (x*-pow(x,2*n)) / rfac(2*n+1) + rek(n - 1,x);

	return n1;


}

float ite(int n, float x)
{
	float n1 = 0;

	for (int i = 0; i <= n; i++)
	{
			n1 += (x*-pow(x, 2 * i)) / rfac(2 * i + 1);
	}
	return n1;
}







int main()
{
	cout << rek(1, 3) << endl;

	cout << ite(1,3);




	system("PAUSE");
	return 0;

}