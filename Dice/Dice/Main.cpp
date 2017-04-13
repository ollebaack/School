#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include "Dice.h"
using namespace std;
int main() 
{

	Dice d1;
	Dice d2;
	cout << "Throw your dices by pressing enter:";
	while (1) 
	{
		
		if (_kbhit())
		{
			char c = _getch();
			if (c == '\r')
			{
				cout << "\n" << "*throwing dices*" << "\n";
				d1.throw_dice();
				d2.throw_dice();
			    cout << d1.read_dice() << "\n";
				cout << d2.read_dice() << "\n";
			}
			else
				return 0;
		}
		



	}
	system("pause");
	return 0;
}