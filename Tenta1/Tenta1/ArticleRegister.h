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
#include "Article.h"
using namespace std;

class ArticleRegister
{
private:
	vector<Article> v;
	//string Newspaper;
public:


	void Add(Article obj)
	{

		v.push_back(obj);
		cout << "du har nu lagt till: " << obj << " i listan" << endl;
		
	}
	string List()
	{
		ostringstream oss;

		for (unsigned i = 0; i < v.size(); i++)
		{
			oss << v[i] << endl;
		}
		return oss.str();
	}

	void Wrtite2File()
	{
		ofstream myfile;

		myfile.open("test.txt");

		myfile << "ArticleRegister" << endl << endl;

		sort(v.begin(), v.end(), compare_price);

		for (unsigned i = 0; i < v.size(); i++)                                //Alt 1
		{
			myfile << "Article: " << v[i] << endl;
		}
	}

	void ReadfromFile()
	{
		v.clear();
		string strRow;
		ifstream fin("test.txt");
		string s;
		getline(fin, strRow);
		getline(fin, strRow);

		while (getline(fin, strRow))
		{
			istringstream iss(strRow);

			//getline(iss, s, ':');
			//iss >> skipws;


			string str;
			Article m;
			iss >> m;

			v.push_back(m);

		}

		fin.close();

	}

	double CalculateTotalValue()
	{
		Article n1;
		double TotalValue = 0;
		for (unsigned i = 0; i < v.size(); i++)
		{
			TotalValue = TotalValue + v[i].getprice();
		}
		return TotalValue;
	}

	static bool compare_price(Article &lop, Article &rop)//std::sort(v.begin(),v.endl), compare
	{
		return lop.getprice() >= rop.getprice();
	}


	ArticleRegister()
	{
		
		//Newspaper = "";
	}

	~ArticleRegister()
	{
	}
};

