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
#include"student.h"
using namespace std;

class studentregister
{
private:
	vector<student> v; 
public:
	void add()
	{
		cout << "lagg till student:";
		student a;
		cin >> a;
		v.push_back(a);
		cout << "du har nu lagt till: " << a << " i listan" << endl;
	}
	string list()
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

		myfile << "Studentregister" << endl << endl;

		for (unsigned i = 0; i < v.size(); i++)                                //Alt 1
		{
			myfile << "Student: " << v[i] << endl;
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
			student m;
			iss >> m;

			v.push_back(m);

		}

		fin.close();

	}

	studentregister()
	{
	}

	~studentregister()
	{
	}
};

