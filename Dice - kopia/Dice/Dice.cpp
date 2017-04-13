#include "Dice.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <iomanip>
using namespace std;

Dice::Dice()
{
	value = 0;
	srand(time(NULL));
}


Dice::Dice(int v)
{
	value = v;
}

void Dice::throw_dice()
{
	value = rand() % 6 + 1;

}

int Dice::read_dice() 
{
	if (value == 1) {
		cout << " -------\n!       !\n!   x   !\n!       !\n -------\n\n";
	}
	else if (value == 2) {
		cout << " -------\n!     x !\n!       !\n! x     !\n -------\n\n";
	}
	else if (value == 3) {
		cout << " -------\n!     x !\n!   x   !\n! x     !\n -------\n\n";
	}
	else if (value == 4) {
		cout << " -------\n! x   x !\n!       !\n! x   x !\n -------\n\n";
	}
	else if (value == 5) {
		cout << " -------\n! x   x !\n!   x   !\n! x   x !\n -------\n\n";
	}
	else if (value == 6) {
		cout << " -------\n! x   x !\n! x   x !\n! x   x !\n -------\n\n";
	}
	return value;
}



Dice::~Dice()
{
}
