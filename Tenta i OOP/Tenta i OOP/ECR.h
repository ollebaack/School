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
#include "EnergyConsumption.h"
using namespace std;

class ECR
{
private:

	vector<EnergyConsumption> v;
	string Fastighet;
public:

	void Add(EnergyConsumption obj)
	{

		v.push_back(obj);
		cout << "du har nu lagt till: " << obj << " i listan" << endl;

	}

	static bool compare(EnergyConsumption &lop, EnergyConsumption &rop)//std::sort(v.begin(),v.endl), compare
	{
		return lop.getStartMätning() <= rop.getStartMätning();
	}

	void *Search(string Name)
	{
		bool hit = false;
		string s;
		cout << "Uthyrningsobjekt: ";
		//cin >> s;
		if (v.size() == 0)
			cout << "There isn't a objekt named that." << endl << endl;

		//sort(v.begin(), v.end(), compare);
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i].getUthyrningsobjekt()==Name)
			{
				cout << v[i] << endl << endl;
				hit = true;
				//return &Name
			}
		}

		if (!hit)
		{
			cout << "There is no Uthyrningsobjekt named that!" << endl;

			return nullptr;
		}
	}

	void Delete(int index)
	{
		bool hit = false;
		string s;
		cout << "Type Uthyrningsobjekt: ";
		//cin >> s;
		if (v.size() == 0)
			cout << "There isn't a objekt named that." << endl << endl;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i].getAntalKilowatt() == index)
			{
				v.erase(v.begin() + i);
				cout << "You successfully deleted the objekt!" << endl << endl;
				hit = true;
				//Write2File();
				break;
			}

		}
		if (!hit)
			cout << "There isn't a objekt named that." << endl;

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

	void Write2File()
	{
		ofstream myfile;

		myfile.open("test.txt");

		myfile << "EnergyConsumption:" << endl << endl;

		sort(v.begin(), v.end(), compare);

		for (unsigned i = 0; i < v.size(); i++)                                //Alt 1
		{
			myfile << "EnergyConsumption: " << v[i] << endl;
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
			EnergyConsumption m;
			iss >> m;

			v.push_back(m);

		}

		fin.close();

	}

	void CalculateEnergyConsumption(string datum)
	{
		/*EnergyConsumption n1;
		double TotalEnergyConsumption = 0;
		for (unsigned i = 0; i < v.size(); i++)
		{
			TotalEnergyConsumption = TotalEnergyConsumption + v[i].getAntalKilowatt();
		}
		return TotalEnergyConsumption;*/
		bool hit = false;
		int s = 0;
		cout << "Antal Kilowatt on that day: ";
		//cin >> s;
		if (v.size() == 0)
			cout << "There isn't a objekt on that day." << endl << endl;

		//sort(v.begin(), v.end(), compare);
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i].getStartMätning() == datum)
			{
				cout << v[i].getAntalKilowatt() << endl << endl;
				hit = true;
			}
		}

		if (!hit)
		{
			cout << "There is no Uthyrningsobjekt on that day!" << endl;

		}

	}


	ECR()
	{
	}

	~ECR()
	{
	}
};

