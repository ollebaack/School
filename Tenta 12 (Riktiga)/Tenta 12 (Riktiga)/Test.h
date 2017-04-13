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
#include <algorithm>
#include <fstream>
#include <sstream>


namespace Tenttt
{
class Test
{

private:
	//map<key1=customer, value1=map<key2=article, value2=antal>>>
	map<string, map<string, int>> m;
	//map<string, int> ma;
	struct Data
	{
		string ip; //Ipnumber
		string num; //Article number
		int n;	//Antal

		Data()
		{
			ip = "";
			num = "";
			n = 0;
		}
		friend bool operator<(const Data &lop, const Data &rop)
		{
			return lop.n < rop.n;
		}
		//Data(long long sum, int n) :sum(sum), n(n){}
	};
	priority_queue<Data> pq;
	vector<Data> v;
	Data da;
public:
	/*Customer() {}*/

	void file2map()
	{
		//ifstream fin("data_log_ecommorce_02.txt");
		ifstream fin("dataLogEcommorceTwoLarge.txt");

		string junk;
		string strRow = "";
		while (std::getline(fin, strRow))
		{
			istringstream iss(strRow);

			string key_customer = "";
			getline(iss, key_customer, ' ');
			//getline(iss, junk, ' ');

			string key_article = "";
			getline(iss, key_article, ' ');
			//getline(iss, junk, ' ');

			int Amount = 0;
			//getline(iss, Amount, ' ');
			iss >> Amount;
			//getline(iss, junk, ' ');
			int u = Amount;
			int n = 0;
			iss >> n;

			////--- Variant 1: Insättning/uppdatering
			m[key_customer][key_article] += n;
		}
		fin.close();
	}

		//friend ostream & operator << (ostream & ut, Data &da)
		//{
		//	ut << '(' << da.ip << " " << da.num << " " << da.n << ' )';
		//	return ut;
		//}

		/*friend istream& operator >> (istream & in, Data &da)
		{
			string s;
			getline(in, da.ip, ' ');
			getline(in, da.num, ' ');
			in >> da.n;

			return in;
		}*/


		/*void Readfromfile()
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
				fin.close();
			}
			catch (exception e)
			{
				cerr << "Exception: " << "dataLogEcommorceTwoLarge.txt" << endl;
				cerr << e.what() << endl;
			}


		}
		*/


	string search(string customer)
	{
		ostringstream oss;
		auto search = m.find(customer);
		if (search != m.end())
		{
			cout << "Kund: " << search->first << " Antal artiklar: " << search->second.size() << endl;
			for (auto d : search->second)
			{
				oss << "Artikel: " << d.first << " : " << d.second << endl;
			}
		}
		else
		{
			oss << "Kund " << customer << " finns ej" << endl;
		}
		return oss.str();
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

		void searchip()
		{
			bool hit = false;
			string s;
			cout << "Type ip: ";
			cin >> s;
			if (v.size() == 0)
				cout << "There isn't a ipnumber like that." << endl << endl;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (v[i].ip == s)
				{
					cout << "Result: " << v[i].ip << " " << v[i].num << " " << v[i].n << endl;
					hit = true;
				}
			}

			if (!hit)
				cout << "There is no ipnumber like that!" << endl;
		}
		void map2pq()
		{
			for (auto &p : v)
			{
				//pq.emplace(Data(p.first, p.second)); //first unikt p.g.a. map
			}
		}

		void printAndPopPriorityQueue(int n)
		{
			for (int i = 0; i < n; i++)
			{
				cout << setw(15) << pq.top().ip << " : " << setw(15) << pq.top().n << endl;
				pq.pop();
			}
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


		Test()
		{
		}

		~Test()
		{
		}

	};

}