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
#include "ECR.h"
using namespace std;


int main()
{
	string s, s1;
	EnergyConsumption n1;
	ECR n2;
	EnergyConsumption obj1;
	EnergyConsumption obj2;



	////Upg 3.1



	//EnergyConsumption n2("bertil", 10, 21, "1996-04-17", "2016-04-17");
	//EnergyConsumption a;
	//a.setUthyrningsObjekt("Olle");
	//a.setAntalKilowatt(20);
	//a.setYta(31);
	//a.setStartMätning("1996-04-17");
	//a.setSlutMätning("2016-04-17");

	//s = n2.to_string();
	//cout << s << endl;

	//s1 = a.to_string();
	//cout << s1 << endl;



	////Upg 3.2



	/*n1.Read();
	n1.Write();*/



	////Upg 3.3


	
	/*cout << "(Uthyrningsobjekt, Kilowatt, Yta, StartMätning(yyyy-mm-dd/hh-mm-ss), SlutMätning(yyyy-mm-dd/hh:mm:ss))" << endl;
	cin >> obj1;
	cout << endl << obj1;*/



	////Upg 3.4



	//istringstream iss("(Olle, 10, 21, 1996-04-17/10:20:30, 2016-04-17/10:20:30)");
	//iss >> obj1;
	//n2.Add(obj1);
	//cout << endl;

	//s = n2.List();
	//cout << s << endl;

	//n2.Delete(10);

	//n2.Search("Olle");

	
	/*istringstream iss("(Olle, 10, 21, 1996-04-17/10:20:30, 2016-04-17/10:20:30)");
	iss >> obj1;
	n2.Add(obj1);
	cout << endl;*/
	


	////Upg 3.5-3.6



	//istringstream isss("(Adam, 10, 21, 1997-04-17/10:20:30, 2017-04-17/10:20:30)");
	//isss >> obj2;
	//n2.Add(obj2);

	//istringstream iss("(Olle, 10, 21, 1996-04-17/10:20:30, 2016-04-17/10:20:30)");
	//iss >> obj1;
	//n2.Add(obj1);
	//cout << endl;

	//n2.Write2File();
	//n2.ReadfromFile();
	//s = n2.List();
	//cout << s;



	////Upg 3.7 
	


	//string h ="1996-04-17/10:20:30";

	//n2.ReadfromFile();

	//s = n2.List();
	//cout << s << endl << endl;
	//n2.CalculateEnergyConsumption(h);


	system("pause");

	return 0;

}