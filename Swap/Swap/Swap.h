#pragma once
class Swap
{
	float *vptr;	int size;
private:
	void create_vector(int s);
	void delete_vector();


public:
	int vector_Swap();
	void set(float value, int index);
	void read_from_keyboard();
	void print();

	Swap();
	~Swap();
};

