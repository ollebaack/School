#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
class Dice
{
private:
	int value;


public:
	void throw_dice();
	int read_dice();

	Dice(int value);

	
	Dice();
	~Dice();
};

