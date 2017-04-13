#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <exception>
#include "Article.h"
using namespace std;
class ArticleRegister
{

private:
	vector<Article> v;
	string newsPaper;

	static bool compare_date(Article &lop, Article &rop)   //std::sort(v.begin(), v.end(), compare. )
	{
		return lop.getDate().compare(rop.getDate()) >= 0;
	}
public:

	void Add(Article a)
	{
		v.push_back(a);
	}
	string List()
	{
		ostringstream oss;

		for (int i = 0; i < v.size(); i++)
		{
			oss << v[i] << endl;
		}
		return oss.str();
	}
	_declspec(noinline)
	void Write2File(string fileName)
	{
		ofstream fout;
		sort(v.begin(), v.end(), compare_date_author);
		fout.open(fileName);
		fout << "ArticleRegister= " << this->newsPaper << endl;                  
		for (int i = 0; i < v.size(); i++)                                //Alt 1
		{
			fout << "Article= " << v[i] << endl;
		}
		
		//for (auto &a : v)                              // Alt 2
	
		//{
		//	fout << "Article= " << a << endl;
		//}
		

	}
	_declspec(noinline)
	void ReadFromFile(string fileName)
	{
		string str, strRow;
		ifstream fin(fileName);
		try {
			v.clear();
			while (getline(fin, strRow))
			{
				istringstream iss(strRow);
				getline(iss, str, '=');   //str==Article eller ArticleRegister
				if (str == "ArticleRegister")
				{
					getline(iss, this->Newspaper);
				}
				else if (str == "Article")
				{
					Article a;
					iss << a;
					if (a.GetId() != -1)
					{
						v.push_back(a);
					}
				} //if
			} //while
			fin.close();
		} //try
		catch (exception e)
		{
			cout << e.what() << endl;
		}
	}
	void SearchWordIn(string word)
	{
		ostringstream oss;

		for (int i = 0; i < v.size(); i++)                   //Alt 1
		{
			if (v[i].GetTitle().find(word) != string::npos)
			{
				oss << v[i] << endl;
			}
		}

	//	for (auto &item : v)                                 //Alt 2
	//	{
	//		if (item.GetTitle().find(word) != string::npos)
	//		{
	//			oss << item << endl;
	//		}
	//		return oss.str();
	//	}
	//}

	ArticleRegister(string title = "")
	{
		this->newsPaper = title;
	}
	~ArticleRegister();
};

