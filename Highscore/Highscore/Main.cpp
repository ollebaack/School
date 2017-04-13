#include <iostream>
#include <conio.h>
#include "Highscore.h"
using namespace std;

int main() {
	int option=1;
	cout << "Welcome to blabla!" << endl << endl;
	cout << "To start game type 1" << endl;
	cout << "To exit type 2" << endl;
	Highscore v1(1);
	
	while (option != 9)
	{
		cout << "1. Enter name." << endl;
		cout << "2. Show names." << endl;
		cout << "3. Enter name." << endl;
		cout << "Enter here: ";
		cin >> option;

		if (option == 1) {
			//spelet
			v1.Enter_name();
			v1.Print();
		
		}

		else if (option == 2) {
			break;
		}

		else
			cout << "Please type '1' to start game or type 2 to exit" << endl;

	}

	system("pause");
	return 0;
}