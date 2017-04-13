#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
class Multimedia
{
protected:
	
public:
	friend ostream& operator<< (ostream& stream, Multimedia& multi);
	friend istream& operator >> (istream& stream, Multimedia& multi);
	int ar;
	string namn;
	

};

