#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
namespace Tent 
{
	class Statistics
	{

	private:



	public:

		struct Data
		{
			long long sum; //Totalsumma för varje pers
			int n;	//Antal pers
	
			Data()
			{
				sum = 0;
				n = 0;
			}
			//Data(long long sum, int n) :sum(sum), n(n){}
		};

		vector<Data> v;
		

		void Readfromfile()
		{
			long long str;
			ifstream fin;
			try
			{
				fin.open("salary.txt");

				if (!fin.good())
				{
					cout << "Couldn't open" << endl;
					return;
				}

				while (fin >> str)
				{
					int Salary = str;
					int i = Salary / 1000;
					v[i].n++;
					v[i].sum += Salary;
				}
				fin.close();
			}
			catch (exception e)
			{
				cerr << "Exception: " << "Salary.txt" << endl;
				cerr << e.what() << endl;
			}


		}


		

		void list()
		{

			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << "Amount of people in " << i << ": " << v[i].n << ". " << "Amount of salary for all people in " << i << ": " << v[i].sum << endl;
			}

		}


		void clear()
		{
			v.clear();
		}

		int calculate_mean()
		{
			long long tmp1 = 0, tmp2 = 0;
			long long medel = 0;
			for (int i = 0; i < v.size(); i++)
			{
				tmp1 += v[i].sum;
			}
			for (int i = 0; i < v.size(); i++)
			{
				tmp2 += v[i].n;
			}
			medel = tmp1 / tmp2;
			return medel;
		}

		//int percentile(int procent)
		//{


		//}

		Statistics()
		{
			v.resize(1000);
		}

		~Statistics()
		{
		}
	};

}