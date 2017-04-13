#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
class Tic_Tac_Toe
{
private:
	char square[10] = { '1','2','3','4','5','6','7','8','9','o' };
	int i;


public:
	char playermarker;
	char currentmove;
	int playerturn = 1;
	int checkwin();
	void play();
	Tic_Tac_Toe();
	void print();
	~Tic_Tac_Toe();
};

