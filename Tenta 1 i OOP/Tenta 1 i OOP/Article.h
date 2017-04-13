#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <exception>
#include "ArticleRegister.h"
using namespace std;

class Article
{
private:
	int id;                      //om int, använd "cin"!
	int n;
	string date;                 //om string, använd "getline"!
	string writer;
	string keyword;
	string title;

public:

	friend ostream& operator << (ostream ut, const Article &a);
	friend istream& operator >> (istream in, Article &a);

	Article(int id = -1, string date = "", string writer = "", int n = 0, string keyword = "");            //id normalt positivt tal.
	int getId() { return id; }
	void setId(int id) { this->id = id; }
	string getKeyword() { return keyword; }
	void Write();
	void Read();
	void main_upg1();
	void main_upg2();
	void main_upg3()
	{
		Article a1(....);
		Article a2(....);
		Article a3(....);
		ArticleRegister ar;
		ar.Add(a1);
		ar.Add(a2);
		ar.Add(a3);
		ar.SetNewspaper("aftonbladet");
		cout << ar.List() << endl;
		ar.Write2File("Text.txt");
	}
	Article();
	~Article();
};

