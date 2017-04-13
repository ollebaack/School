#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include<exception>
#include "student.h"
#include "studentregister.h"
using namespace std;

void test_upg1_2()
{
	cout << "upg1och2" << endl;
	student a1("bertil","svensson",21);
	student a;
	a.setinskrivningar(34);
	a.setfornamn("grek");
	a.setefternamn("stjart");
	cout << a.getfornamn() <<"." ;
	cout << a.getefternamn() <<".";
	cout << a.getinskrivningar() << endl;
	a1.write();
	a1.read();
	a1.write();
}
void test_upg3()
{
	string str;
	student a;
	student a1("bertil", "svensson", 21);
	cout << "upgift3:" << endl;
	cout << a1;

	cin >> a1;
	//cin.get();
	std::getline(cin, str);
	cout << a1 << endl;
}
void test_upg4()
{

	studentregister sr;
	
	//sr.add();
	//sr.add();
	//string s = sr.list();
	//cout << "studentregister:" << endl;
	//cout << s << endl;
	//sr.Wrtite2File();
	
	sr.ReadfromFile();
	string s = sr.list();
	cout << s << endl;
}

int main()
{
	
	//test_upg1_2();
	//test_upg3();
	test_upg4();
	
	system("pause");
	return 0;
 }