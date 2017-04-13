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
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <fstream>
#include <sstream>
namespace Tent
{
	class Statistic
	{
	private:



	public:

		struct Data
		{
			string ip; //Ipnumber
			string num; //Article number
			int n;	//Antal

			/*Data()
			{
				ip = "";
				num = "";
				n = 0;
			}*/
			Data(string ip = "",string num = "", int n = 0) : ip(ip), num(num), n(n) {}

			friend bool operator<(const Data &lop, const Data &rop)
			{
				return lop.n < rop.n;
			}
			string string2() const
			{
				ostringstream oss;

				oss << "Article " << num << " Have been bought from this many different people: " << n << endl;
				return oss.str();
			}
		};

		vector<Data> v;

		friend ostream & operator << (ostream & ut, Data &da)
		{
			ut << '(' << da.ip << " " << da.num << " " << da.n << ' )';
			return ut;
		}

		friend istream& operator >> (istream & in, Data &da)
		{
			string s;
			getline(in, da.ip, ' ');
			getline(in, da.num,' '); 
			in >> da.n; 

			return in;
		}
		priority_queue<Data> pq;

		void Readfromfile()
		{
			string strRow;
			ifstream fin;
			try
			{
				fin.open("dataLogEcommorceTwoLarge.txt");

				if (!fin.good())
				{
					cout << "Couldn't open" << endl;
					return;
				}

				while (getline(fin, strRow))
				{
					istringstream iss(strRow);
					Data d;
					iss >> d;

					v.push_back(d);
				}
				for (size_t i = 0; i < v.size(); i++)
				{
					pq.emplace(Data(v[i].ip, v[i].num, v[i].n));
				}
				fin.close();
			}
			catch (exception e)
			{
				cerr << "Exception: " << "dataLogEcommorceTwoLarge.txt" << endl;
				cerr << e.what() << endl;
			}


		}




		void list()
		{
			//ostringstream oss;
			//
			//	for (int i = 0; i < v.size(); i++)
			//	{
			//		oss << v[i] << endl;
			//	}
			//	return oss.str();
			for (int i = 0; i < v.size(); i++)
					{
						cout << "Ipnumber: " << v[i].ip << " " << v[i].num << " " << v[i].n << endl;
					}
				

		}

		void print()
		{
			for (size_t i = 0; i < 100; i++)
			{
				cout << pq.top().string2();
				pq.pop();
			}

		}

		void searchart()
		{
			bool hit = false;
			int summa = 0;
			string s;
			cout << "Type art: ";
			cin >> s;
			if (v.size() == 0)
				cout << "There isn't a ipnumber like that." << endl << endl;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i].num == s)
				{
					summa += v[i].n;
					cout << "Result: " << v[i].ip << " " << v[i].num << " " << v[i].n << endl;

					hit = true;
				}
			}
			cout << endl;
			cout << "Total summan: " << summa << endl;
			if (!hit)
				cout << "There is no ipnumber like that!" << endl;
		}

		void searchip()
		{
			bool hit = false;
			int summa = 0;
			string s;
			cout << "Type ip: ";
			cin >> s;
			if (v.size() == 0)
				cout << "There isn't a ipnumber like that." << endl << endl;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i].ip == s)
				{
					summa += v[i].n;
					cout << "Result: " << v[i].ip << " " << v[i].num << " " << v[i].n << endl;

					hit = true;
				}
			}
			cout << endl;
			cout << "Total summan: " << summa << endl;
			if (!hit)
				cout << "There is no ipnumber like that!" << endl;
		}
		
		void clear()
		{
			v.clear();
		}

		//int calculate_mean()
		//{
		//	long long tmp1 = 0, tmp2 = 0;
		//	long long medel = 0;
		//	for (int i = 0; i < v.size(); i++)
		//	{
		//		tmp1 += v[i].sum;
		//	}
		//	for (int i = 0; i < v.size(); i++)
		//	{
		//		tmp2 += v[i].n;
		//	}
		//	medel = tmp1 / tmp2;
		//	return medel;
		//}


		Statistic()
		{
			//v.resize(1000);
		}

		~Statistic()
		{
		}
	};

}