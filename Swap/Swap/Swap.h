#pragma once
class Swap
{
	float *vptr;
private:

	void delete_vector();


public:
	int vector_Swap();
	void set(float value, int index);
	void read_from_keyboard();
	void print();

	Swap();
	~Swap();
};
