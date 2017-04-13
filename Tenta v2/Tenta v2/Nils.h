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
	class Nils
	{
	private:
		map<string, int> dictionary;
	
		struct Data
		{
			string word; //Ordet
			int n;	//Antal ord

			Data(string word = "", int n = 0) : word(word), n(n){}

			friend bool operator<(const Data &lop, const Data &rop)
			{
				return lop.n < rop.n;
			}
		};

		struct Compare
		{
			bool operator() (pair<string, int> i, pair<string, int> j) { return i.second < j.second; }
		};
		Compare compare;

		priority_queue<Data> pq;
	public:

		void Readfromfile()
		{
			string strRow;
			ifstream fin;
			try
			{
				fin.open("nils_holgersson.txt");

				if (!fin.good())
				{
					cout << "Couldn't open" << endl;
					return;
				}

				while (!fin.eof())
				{
					string s;
					fin >> s;

					auto p = dictionary.emplace(s, 1);
					if (p.second == false)
						p.first->second++;

				}
				fin.close();
			}
			catch (exception e)
			{
				cerr << "Exception: " << "nils_holgersson.txt" << endl;
				cerr << e.what() << endl;
			}
		}

		int totalNumbersOfWords()
		{
			int total_words = 0;
			for (auto &p : dictionary)
			{
				total_words += p.second;
			}

			return total_words;
		}

		string maxFrequency()
		{
			ostringstream oss;

			auto it = std::max_element(dictionary.begin(), dictionary.end(), compare);
			oss << "[" << it->first << ": " << it->second << "]";

			return oss.str();
		}

		void map2pq()
		{
			for (auto &p : dictionary)
			{
				pq.emplace(Data(p.first, p.second)); //first unikt p.g.a. map
			}
		}

		void printAndPopPriorityQueue(int n)
		{
			for (int i = 0; i < n; i++)
			{
				cout << setw(15) << pq.top().word << " : " << setw(15) << pq.top().n << endl;
				pq.pop();
			}
		}
	

		Nils()
		{
		}

		~Nils()
		{
		}
	};
}
