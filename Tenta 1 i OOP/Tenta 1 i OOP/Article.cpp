#include "Article.h"
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

Article::Article(int id, string date, string writer, int n, string keyword)
{
	this->id = id;
	this->n = n;
	this->date = date;
	this->writer = writer;
	this->keyword = keyword;
	//this->title = title;
}

void Article::Write()
{
	cout << "id=" << id << endl;

	cout << "keyword=" << keyword << endl;
}

void Article::Read()
{
	cout << "Id= ";
	cin >> id; // (Enter) = '\n' ligger kvar i tecken
	getline(cin, str); // Läser bort
	cout << "Date= ";
	getline(cin, date);
}

void Article::main_upg1()
{
	cout << "3.1.2 \n";
	Article a1;
	Article a2(1, "2011-11-10", "Kris", "Johan", 200, "nyhet");
	a1.Write();
	a2.Write();
	a1.Read();
	a2.Read();
	a1.SetWriter("Kalle");
	a1.Write();
}

void Article::main_upg2()
{
	cout << "3.3\n";
	string str;
	Article a1;
	Article a2(...);

	cout << a1 << endl;
	cout << a2 << endl;

	istringstream iss("(3, 2011-11-10, Fotboll, Andus, 150, Sport)");
	iss >> a1;                                                             //cin >> a1;   Använder istringstream ist för cin.

	cout << a1 << endl;
}

Article::Article()
{
}


Article::~Article()
{
}

ostream & operator<<(ostream ut, const Article & a)
{
	out << "(";
	out << a.id << ",";
	out << a.date << ",";
	out << a.writer << ",";
	out << a.keyword << ")";
	return out;
}

istream & operator >> (istream in, Article & a)
{
	
		string s;
		getline(in, s, '(');

		in >> skipws >> a.id;
		getline(in, s, ',');

		in >> skipws;
		getline(in, a.date, ',');

		in >> skipws;
		getline(in, a.writer, ',');             //Lägg till "n" och "title"

		in >> skipws;
		getline(in, a.keyword, ',');

		getline(in, s, ')');

		return in;
	
}
