#pragma once
#include <iostream>
#include <vector>

using namespace std;
class matrix_float
{
private:
	float **mptr;
	int r_size;
	int c_size;
	void create_matrix(int r, int c);
	void delete_matrix();
public:
	void read_from_keyboard();
	void print();
	matrix_float(int r, int c);
	~matrix_float();
};

