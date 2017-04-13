#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <exception>
using namespace std;
#include "Article.h"
#include "ArticleRegister.h"


int main()
{

	Article n1;

	//Upg 1
	//cout << "skriv in article nummer: ";
	//cin >> n1.number;
	//cout << endl << "skriv in article namn: ";
	//cin >> n1.name;
	//cout << endl << "skriv in pris: ";
	//cin >> n1.price;

	//cout << endl << "Beräkna procent: ";
	//double p;
	//cin >> p;
	//n1.CalculateCustomerPrice(p);
	//cout << endl << endl;
	//cout << n1.number << ", " << n1.name << ", " << n1.price << ", (" << n1.customerPrice << ")";
	//cout << endl;


	//upg 2
	//n1.Read();
	//n1.Write();

	//upg 3
	Article obj1;
	/*cout << "(number, Name, Price)" << endl;
	cin >> obj1;
	cout << endl << obj1;
*/
	//upg 4
	/*string s;
	ArticleRegister n2;
	istringstream iss("(1, olle, 1000)");
	iss >> obj1;
	n2.Add(obj1);
	cout << endl;
	s = n2.List();
	cout << s;
*/

	//5 och //6
	Article obj2;
	string s;
	ArticleRegister n2;
	//istringstream iss("(1, olle, 1000)");
	//iss >> obj1;
	//n2.Add(obj1);
	//cout << endl;

	//n2.Wrtite2File();
	//n2.ReadfromFile();
	//s = n2.List();
	//cout << s;


	//7
	//double d;
	//istringstream iss("(1, olle, 1000)");
	//iss >> obj1;
	//istringstream isis("(1, adam, 100)");
	//isis >> obj2;
	//obj2.setprice(234);
	//n2.Add(obj1);
	//cout << endl;
	//n2.Add(obj2);
	//cout << endl;
	//n2.Wrtite2File();
	//d = n2.CalculateTotalValue();
	//cout << "TotalValueof price: " << d << endl;
	system("pause");

	return 0;
}