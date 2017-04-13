#pragma once
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include<exception>

using namespace std;
class student
{
private: 
	string fornamn;
	string efternamn;
	int inskrivningar;

public:
	string getfornamn() 
	{
		return fornamn;
	}
	
	void setfornamn(string fornamn)
	{
		this->fornamn = fornamn;
	}
	
	string getefternamn()
	{
		return efternamn;
	}
	
	void setefternamn(string efternamn)
	{
		this->efternamn = efternamn;
	}
	
	int getinskrivningar()
	{
		return inskrivningar;
	}
	
	void setinskrivningar(int inskrivningar)
	{
		this->inskrivningar = inskrivningar;
	}
	void read()
	{
		string str;
		cout << setw(15) << "fornamn:" ;
		cin >> fornamn;
		//getline(cin, str);
		cout << setw(15) <<  "efternamn:";
		cin >> efternamn;
		//getline(cin, str);
		cout << setw(5) << "inskrivningar:";
		cin >> inskrivningar;
		cout<< endl;
		getline(cin, str);
	}
	void write()
	{
		cout << "fornamn:" << fornamn << setw(20);
		cout << "efternamn:" << efternamn << setw(20);
		cout << "inrskrivningsar:" << inskrivningar<<setw(20) << endl;
	}
	friend ostream& operator <<(ostream& out, const student &a)
	{
		out << "(";
		out << a.fornamn << ",";
		out << a.efternamn << ",";
		out << a.inskrivningar << ")";
		return out;
	}
	friend istream& operator >> (istream& in, student& a)
	{
		string s,j;
		getline(in, s, '(');
		in >> skipws ;
		getline(in, a.fornamn, ',');
		in >> skipws;
		getline(in, a.efternamn, ',');
		in >> skipws >> a.inskrivningar;
		getline(in, j, ')');
		return in;
	
	}
	student(string fornamn = "",string efternamn = "", int inskrivningar = 0) //defaultkonstruktor
	{
		this->fornamn = fornamn;
		this->efternamn = efternamn;
		this->inskrivningar = inskrivningar;

	}
	
};

