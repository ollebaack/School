#pragma once
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
class EnergyConsumption
{
private:
	string Uthyrningsobjekt;
	string StartM�tning; //yyyymmdd
	string SlutM�tning;  //yyyymmdd
	int AntalKilowatt;
	int Yta; //kvadratmeter

public:
	

	friend ostream& operator<<(ostream& out, const EnergyConsumption &EnergyConsumption)
	{
		out << "(" << EnergyConsumption.Uthyrningsobjekt << ", " << EnergyConsumption.AntalKilowatt << ", " << EnergyConsumption.Yta << "," << EnergyConsumption.StartM�tning << "," << EnergyConsumption.SlutM�tning << ")";
		return out;
	}
	friend istream& operator >> (istream& in, EnergyConsumption& EnergyConsumption)
	{

		string s, j;
		getline(in, s, '(');
		//in >> skipws;
		getline(in, EnergyConsumption.Uthyrningsobjekt, ',');
		in >> skipws;
		in >> EnergyConsumption.AntalKilowatt;
		getline(in, s, ',');
		in >> skipws >> EnergyConsumption.Yta;
		getline(in, s, ',');
		getline(in, EnergyConsumption.StartM�tning, ',');
		in >> skipws;
		getline(in, EnergyConsumption.SlutM�tning, ')');

		return in;

	}

	EnergyConsumption(string Uthyrningsobjekt = "", int AntalKilowatt = 0, int Yta = 0, string StartM�tning = "", string SlutM�tning = "")           
	{
		this->Uthyrningsobjekt = Uthyrningsobjekt;
		this->AntalKilowatt = AntalKilowatt;
		this->Yta = Yta;
		this->StartM�tning = StartM�tning;
		this->SlutM�tning = SlutM�tning;
	}

	string getUthyrningsobjekt() { return Uthyrningsobjekt; }
	void setUthyrningsObjekt(string UthyrningsObjekt) { this->Uthyrningsobjekt = UthyrningsObjekt; }
	string getStartM�tning() { return StartM�tning; }
	void setStartM�tning(string StartM�tning) { this->StartM�tning = StartM�tning; }
	string getSlutM�tning() { return SlutM�tning; }
	void setSlutM�tning(string SlutM�tning) { this->SlutM�tning = SlutM�tning; }
	int getAntalKilowatt() { return AntalKilowatt; }
	void setAntalKilowatt(int AntalKilowatt) { this->AntalKilowatt = AntalKilowatt; }
	int getYta() { return Yta; }
	void setYta(int Yta) { this->Yta = Yta; }

	void Write()
	{
		cout << "Uthyrningsobjekt= " << Uthyrningsobjekt << endl;

		cout << "AntalKilowatt= " << AntalKilowatt << endl;

		cout << "Yta= " << Yta << endl;

		cout << "StartM�tning= " << StartM�tning << endl;

		cout << "SlutM�tning= " << SlutM�tning << endl;
	}

	void Read()
	{
		string str;
		cout << "Uthyrningsobjekt: ";
		cin >> Uthyrningsobjekt; // (Enter) = '\n' ligger kvar i tecken
		getline(cin, str); // L�ser bort
		cout << "AntalKilowatt: ";
		cin >> AntalKilowatt;
		getline(cin, str); // L�ser bort
		cout << "Yta: ";
		cin >> Yta;
		getline(cin, str);
		cout << "StartM�tning: ";
		cin >> StartM�tning;
		getline(cin, str); // L�ser bort
		cout << "SlutM�tning: ";
		cin >> SlutM�tning;
		getline(cin, str); // L�ser bort

	}

	string to_string()   //List
	{
		ostringstream oss;

		oss << "(" << Uthyrningsobjekt << ", " << AntalKilowatt << ", " << Yta << ", " << StartM�tning << ", " << SlutM�tning << ")";

		return oss.str();
	}


	//EnergyConsumption()
	//{
	//}

	~EnergyConsumption()
	{
	}
};

