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

using namespace std;
class Article
{

private:
	string name;
	double price;
	int number;
	double customerPrice;
public:


	friend ostream& operator<<(ostream& out, const Article& article)
	{
		out << "(" << article.number << ", " << article.name << ", " << article.price << ")";
		return out;
	}
	friend istream& operator >> (istream& in, Article& article)
	{

		string s, j;
		getline(in, s, '(');
		//in >> skipws;
		in >> article.number;
		getline(in, s, ',');
		in >> skipws;
		getline(in, article.name, ',');
		in >> skipws >> article.price;
		getline(in, j, ')');
		return in;

	}

	Article(int number = 0, string name = "", double price = 0)            //id normalt positivt tal.
	{
		this->number = number;
		this->name = name;
		this->price = price;

	}

	int getnumber() { return number; }
	void setprice(double price) { this->price = price; }
	string getname() { return name; }
	double getprice() { return price; }

	void Write()
	{
		cout << "Number= " << number << endl;

		cout << "Name= " << name << endl;

		cout << "Price= " << price << endl;
	}

	void Read()
	{
		string str;
		cout << "Number: ";
		cin >> number;
		getline(cin, str); // Läser bort
		cout << "Name: ";
		cin >> name; // (Enter) = '\n' ligger kvar i tecken
		getline(cin, str); // Läser bort
		cout << "Price: ";
		cin >> price;
		getline(cin, str);

	}

	
	void CalculateCustomerPrice(double procent)
	{
		customerPrice = procent*price/100;
	}

	void Main_upg_1()
	{
		//cout << "3.1.2 \n";
		//Article a1;
		//Article a2(1, "Kris", 200);
		//a1.Write();
		//a2.Write();
		//a1.Read();
		//a2.Read();
		//a1.SetWriter("Kalle");
		//a1.Write();
	}
	~Article()
	{
	}
};

