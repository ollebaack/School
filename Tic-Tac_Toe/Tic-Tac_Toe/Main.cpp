#include <iostream>
#include "Tic_Tac_Toe.h"
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
int main() {
	Tic_Tac_Toe ttt;


	cout << "Welcome to Tic Tac Toe! Type in a number to select one of following options" << "\n\n";

	int choice=0;
	
	while (choice != 2)
	{
		cout << "1. Play (requires 2 players)" << "\n";
		cout << "2. Exit game" << "\n\n";
		cout << "Option: ";
		cin >> choice;

		if (choice == 1)
		{
			ttt.print();
			ttt.play();


		}
		else if (choice == 2) {
			return 0;

		}


		else
			cout << "Please type in one of following options" << "\n";
	

	}
	system("PAUSE");
	return 0;
}