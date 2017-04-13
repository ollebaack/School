#include "matrix_float.h"
#include <iostream>
#include <vector>

using namespace std;




matrix_float::matrix_float(int r, int c)
{
	if (r > 0 || c > 0)
		create_matrix(r, c);
	else
		cout << "fel";

	
}

void matrix_float::create_matrix(int r, int c)
{
	r_size = r;
	c_size = c;
	mptr = new float*[r];
	for (int i = 0; i < r_size; i++)
	{
		mptr[i] = new float[c];
	}
}

void matrix_float::delete_matrix()
{
	r_size = 0;
	c_size = 0;
	for (int i = 0; i < r_size; i++)
	{
		delete[]mptr[i];
	}
	delete[]mptr;
}

void matrix_float::read_from_keyboard()
{
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			cout << "mata in tal:";
			cin >> mptr[i][j];
		}
	}
}

void matrix_float::print()
{
	for (int i = 0; i < r_size; i++)
	{
		for (int j = 0; j < c_size; j++)
		{
			cout << mptr[i][j] << " ";
		}
		cout  << endl;
	}
}

matrix_float::~matrix_float()
{
	delete_matrix();
}
