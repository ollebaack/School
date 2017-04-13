#include "Vector_float.h"
#include <iostream>
#include <vector>

using namespace std;


void Vector_float::create_vector(int s)
{
	size = s;
	vptr = new float[s];
}

void Vector_float::delete_vector()
{
	size = 0;
	delete[]vptr;
}


void Vector_float::read_from_keyboard()
{
	for (int i = 0; i < size; i++)
	{
		cout << "mata in tal:";
		cin >> vptr[i];
	}
}

void Vector_float::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << vptr[i];
	}
}


Vector_float::Vector_float(int s)
{
	if (s > 0)
		create_vector(s);
	else
		cout << "fel";
}


Vector_float::~Vector_float()
{
	delete_vector();
}
