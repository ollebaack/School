#pragma once
#include <string>
using namespace std;

class Car
{


private:
	string brand;
	int year;
	double price;

public:
	Car();
	Car(string b, int y, double p);
	~Car();
};

