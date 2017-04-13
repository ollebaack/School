#include "Highscore.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;



void Highscore::Create_player(int s)
{
	size = s;
	v = new string[s];
}

void Highscore::Delete_player()
{
	size = 0;
	delete[]&v;
}



void Highscore::Enter_name()
{

	string name;
	
		cout << "Enter name here: ";
		cin >> name;
		v.push_back(name);

}


void Highscore::Print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}



Highscore::Highscore(int s)
{
		Create_player(s);
}


Highscore::~Highscore()
{
	Delete_player();
}
