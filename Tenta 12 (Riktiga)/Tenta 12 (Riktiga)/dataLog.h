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
#include <map>
#include <queue>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <memory>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <functional>
namespace Tentt
{
class dataLog
{
private:
	map<string, int> dictionary;
	//map<string, map<string, int>> dictionary;
	struct Data
	{
		string ip; //Ipnumber
		string num; //Article number
		int n;	//Antal

		Data(/*string ip = "",*/string num = "" , int n = 0) : /*ip(ip),*/ num(num), n(n) {}

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

	//struct Compare
	//{
	//	bool operator() (pair<string, int> i, pair<string, int> j) { return i.second < j.second; }
	//};
	//Compare compare;
	//vector<Data> v;
	priority_queue<Data> pq;
	Data da;

public:

		void Readfromfile()
		{
			string strRow;
			ifstream fin;
			try
			{
				fin.open("dataLogEcommorceTwoSmall.txt");

				if (!fin.good())
				{
					cout << "Couldn't open" << endl;
					return;
				}

				while (getline(fin, strRow))
				//while (!fin.eof())
				{
					string s;
					istringstream iss(strRow);
					string ip, junk, art;
					int n;

					getline(iss, ip, ' ');
					getline(iss, art, ' ');
					getline(iss, junk, ' ');
					n = 1;
					//v.push_back(ip);
					
					//iss >> n;
					//iss >> da;
					//getline(iss, junk, '\n');
					//fin >> s;
					auto p = dictionary.emplace(art, n);
					if (p.second == false)
						p.first->second += n;
						//for (size_t i = 0; i < v.size(); i++)
						//{
						//	if (ip != v[i])
						//		p.first->second += n;
						//}
				}
				fin.close();
				for (auto &a : dictionary)
					pq.emplace(Data(a.first, a.second));
			}
			catch (exception e)
			{
				cerr << "Exception: " << "dataLogEcommorceTwoSmall.txt" << endl;
				cerr << e.what() << endl;
			}
		}

		//int totalNumbersOfWords()
		//{
		//	int total_words = 0;
		//	for (auto &p : dictionary)
		//	{
		//		total_words += p.second;
		//	}

		//	return total_words;
		//}



		/*string maxFrequency()
		{
			ostringstream oss;

			auto it = std::max_element(dictionary.begin(), dictionary.end(), compare);
			oss << "[" << it->first << ": " << it->second << "]";

			return oss.str();
		}*/


		void printAndPopPriorityQueue(int n)
		{
			for (int i = 0; i < n; i++)
			{
				cout << setw(15) << pq.top().ip << " : " << setw(15) << pq.top().n << endl;
				pq.pop();
			}
		}

		void print()
		{
			for (size_t i = 0; i < 10; i++)
			{
				cout << pq.top().string2();
				pq.pop();
			}

		}

		dataLog()
		{
		}

		~dataLog()
		{
		}

	};
}
