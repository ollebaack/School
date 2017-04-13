#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include "Multimedia.h"
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Register.h"


int main() {

	int x = 1;
	Register n1;

	Multimedia v1;
	n1.ReadFromFile(); //KjellCarry

	while (x != 8)
	{
		cout << "Choose between" << endl << endl;
		cout << "1. Add to file" << endl;
		cout << "2. Search in file" << endl;
		cout << "3. Delete a file" << endl;
		cout << "4. Print out all songs" << endl;
		cout << "5. Write to file" << endl;
		cout << "6. Read from file" << endl;
		cout << "7. Sort after year" << endl;
		cout << "8. Quit" << endl;
		cout << "Val: ";
		cin >> x;
		cin.get();
		cout << endl;

		switch (x)
		{
		case 1:
			cout << "Add to file" << endl;
			n1.add();
			break;

		case 2:
			cout << "Search in file" << endl;
			n1.search();
			break;

		case 3:
			cout << "Delete a file" << endl;
			n1.delete_multi();
			break;
		case 4:
			cout << "List of all songs:" << endl;
			n1.List();
			break;
		case 5:
			n1.WriteFile();
			break;
		case 6:
			n1.ReadFromFile();
			break;
		case 7:
			n1.sort();
			break;
		case 8:
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;

}