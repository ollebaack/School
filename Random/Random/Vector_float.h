#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Vector_float
{
private:
	float *vptr;
	int size;
	void create_vector(int s);
	void delete_vector();
public:
	void read_from_keyboard();
	void print();
	Vector_float(int s);
	~Vector_float();
};

