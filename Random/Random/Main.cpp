#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include "matrix_float.h"
using namespace std;
#include <vector>
#include <iostream>
using namespace std;
int main()
{

	int r, c;
	cout << "mata in x antal rader: ";
	cin >> r;
	cout << endl << "mata in x antal columner: ";
	cin >> c;

	{
		matrix_float v(r, c);
		v.read_from_keyboard();
		v.print();
	}





	system("pause");
	return 0;
}