#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

//int fac(int n)
//{
//	int n1;
//	
//	if (n <= 0)
//		return 1;
//
//	else
//		n1 = n * fac(n - 1);
//	
//	return n1;
//	
//}
//
//int fac1(int n)
//{
//	int n1 = 1;
//
//	for (int i = n; i > 0; i--)
//	{
//		n1 = n1 * i;
//		
//	}
//	return n1;
//	
//}



//void triangle(ostream& out, unsigned int m, unsigned int n)
//{
//	
//
//		if (m > n)
//			return;
//
//
//		else
//		{
//
//			for (unsigned int i = 0; i < m; i++)
//			{
//				cout << "*";
//			}
//			cout << endl;

//			triangle(cout,m+1, n);

//			for (unsigned int i = 0; i < m; i++)
//			{
//				cout << "*";
//			}
//			cout << endl;
//		}
//
//	
//}


//int fibb(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//
//	else
//	{
//			return fibb(n - 1) + fibb(n - 2);
//		
//	}
//
//}
//
//void print_fibb(int n) {
//	for (int i = 0; i < n; i++)
//	{
//		cout << fibb(i) << ", ";
//	}
//}
//

void fibb1(int n)
{
	int t;
	int n1 = 0;


	for (int i = 0; i < n; i++)
	{
		if (n1 == 0)
			cout << 0 << ", ";
		else if (n1 == 1)
			cout << 1 << ", ";
		else
		{
			t = (n1 - 1) + (n1 - 2);
			cout << t << ", ";
		}
		n1++;
	}
}


int main()
{
	int t = 0;
	int s = 0;



	cout << "Pick a number: ";
	cin >> t;

	fibb1(t);

	system("pause");
	return 0;
}