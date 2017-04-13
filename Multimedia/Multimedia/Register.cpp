#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include "Multimedia.h"
#include "Register.h"
using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>


void Register::add()
{
	Multimedia obj1;
	cout << "Songtitle: ";
	cin >> obj1.namn;
	cout << "Year: ";
	cin >> obj1.ar;
	cout << endl;
	if (obj1.ar >= 0)
	{
		v.push_back(obj1);
		cout << "Your song was successfully added" << endl << endl;
	}
	else
		cout << "ERROR! There is no song made that year..." << endl << endl;

}



void Register::delete_multi()
{
	bool hit = false;
	string s;
	cout << "Type songname: ";
	cin >> s;
	if (v.size() == 0)
		cout << "There isn't a song named that." << endl << endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].namn == s)
		{
			v.erase(v.begin() + i);
			cout << "You successfully deleted the file!" << endl << endl;
			hit = true;
			WriteFile();
			break;
		}
		
	}
	if (!hit)
		cout << "There isn't a song named that." << endl;
}

void Register::search()
{
	bool hit = false;
	string s;
	cout << "Type songname: ";
	cin >> s;
	if (v.size() == 0)
		cout << "There isn't a song named that." << endl << endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].namn == s)
		{
			cout << i+1 << ". " << v[i] << endl << endl;
			hit = true;
		}	
	}

	if (!hit)
		cout << "There is no song named that!" << endl;
}

void Register::List()
{
	system("cls");
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << i+1 << ". " << v[i] << endl;
	}
}

Register::Register()
{
}
ostream & operator<<(ostream & stream, Multimedia & multi)
{
	stream << multi.namn << " " << multi.ar;
	return stream;
}

istream& operator >> (istream & stream, Multimedia & multi)
{

	stream >> multi.namn;
	stream >> multi.ar;
	return stream;
}

void Register::WriteFile()
{
	ofstream myfile;
	myfile.open("SongList.txt");
	myfile << "Song List:" << endl << endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		myfile << i+1 << ". " << v[i] << endl;
	}
	ReadFromFile();
	myfile.close();
}

void Register::ReadFromFile()
{
	v.clear();
	string strRow;
	ifstream fin("SongList.txt");
	string s;
	getline(fin, strRow);
	getline(fin, strRow);

	while (getline(fin, strRow))
	{
		istringstream iss(strRow);
		
		getline(iss, s, '.');
		iss >> skipws;
		string str;
		Multimedia m;
		iss >> m;

		v.push_back(m);

	}

	fin.close();

}

bool cmp_ar(Multimedia &l, Multimedia &r)
{
	return l.ar < r.ar;
}

bool cmp_name(Multimedia &l, Multimedia &r)
{
	return l.namn < r.namn;
}

void Register::sort()

{
	string s;
	system("cls");
	cout << "How would you like to sort your list?" << endl;
	cout << "By name or year?" << endl;
	while (s != "year" && s != "name")
	{
		cout << "Type here: ";
		cin >> s;
		cout << endl;

		if (s == "year")
		{
			std::sort(v.begin(), v.end(), cmp_ar);
			cout << "You successfully sorted your list!" << endl;
			WriteFile();
		}
		else if (s == "name")
		{
			std::sort(v.begin(), v.end(), cmp_name);
			cout << "You successfully sorted your list!" << endl;
			WriteFile();
		}
		else
			cout << "Please type either name or year" << endl;
	}
}

Register::~Register()
{

}
