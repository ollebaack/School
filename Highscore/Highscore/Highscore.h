#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Highscore
{
private:
	vector<string> v;
	int size;
	void Create_player(int s);
	void Delete_player();
public:
	void Print();
	void Enter_name();
	Highscore(int s);
	~Highscore();
};

