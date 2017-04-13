#include <iostream>
using namespace std;
#include <string>
int main()
{
	string namn, date, answer;
	int Age;
	cout << "Hi! My name is Bertil, whats your name? \n";
	cin >> namn;
	cout << "Hi! " << namn;
	cout << "\n How old are you, " << namn << "? \n";
	cin >> Age;
	cout << "\nOkey " << namn << ", Im 66, want to date? \n";
	while (1) {
		cin >> date;
		if (date == "yes")
		{
			cout << "\nNice! seeya 8 clock at my place! \n";
			cin >> answer;
			break;
		}
		else if (date == "no")
		{
			cout << "\n fuck you bitch! \n";
			break;
		}
		else
		{
			cout << "\n wtf you sayin? plz answer yes or no \n";
		}
	}
	system("pause");
	return 0;
}