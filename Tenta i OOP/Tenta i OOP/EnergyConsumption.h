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
	string StartMätning; //yyyymmdd
	string SlutMätning;  //yyyymmdd
	int AntalKilowatt;
	int Yta; //kvadratmeter

public:
	

	friend ostream& operator<<(ostream& out, const EnergyConsumption &EnergyConsumption)
	{
		out << "(" << EnergyConsumption.Uthyrningsobjekt << ", " << EnergyConsumption.AntalKilowatt << ", " << EnergyConsumption.Yta << "," << EnergyConsumption.StartMätning << "," << EnergyConsumption.SlutMätning << ")";
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
		getline(in, EnergyConsumption.StartMätning, ',');
		in >> skipws;
		getline(in, EnergyConsumption.SlutMätning, ')');

		return in;

	}

	EnergyConsumption(string Uthyrningsobjekt = "", int AntalKilowatt = 0, int Yta = 0, string StartMätning = "", string SlutMätning = "")           
	{
		this->Uthyrningsobjekt = Uthyrningsobjekt;
		this->AntalKilowatt = AntalKilowatt;
		this->Yta = Yta;
		this->StartMätning = StartMätning;
		this->SlutMätning = SlutMätning;
	}

	string getUthyrningsobjekt() { return Uthyrningsobjekt; }
	void setUthyrningsObjekt(string UthyrningsObjekt) { this->Uthyrningsobjekt = UthyrningsObjekt; }
	string getStartMätning() { return StartMätning; }
	void setStartMätning(string StartMätning) { this->StartMätning = StartMätning; }
	string getSlutMätning() { return SlutMätning; }
	void setSlutMätning(string SlutMätning) { this->SlutMätning = SlutMätning; }
	int getAntalKilowatt() { return AntalKilowatt; }
	void setAntalKilowatt(int AntalKilowatt) { this->AntalKilowatt = AntalKilowatt; }
	int getYta() { return Yta; }
	void setYta(int Yta) { this->Yta = Yta; }

	void Write()
	{
		cout << "Uthyrningsobjekt= " << Uthyrningsobjekt << endl;

		cout << "AntalKilowatt= " << AntalKilowatt << endl;

		cout << "Yta= " << Yta << endl;

		cout << "StartMätning= " << StartMätning << endl;

		cout << "SlutMätning= " << SlutMätning << endl;
	}

	void Read()
	{
		string str;
		cout << "Uthyrningsobjekt: ";
		cin >> Uthyrningsobjekt; // (Enter) = '\n' ligger kvar i tecken
		getline(cin, str); // Läser bort
		cout << "AntalKilowatt: ";
		cin >> AntalKilowatt;
		getline(cin, str); // Läser bort
		cout << "Yta: ";
		cin >> Yta;
		getline(cin, str);
		cout << "StartMätning: ";
		cin >> StartMätning;
		getline(cin, str); // Läser bort
		cout << "SlutMätning: ";
		cin >> SlutMätning;
		getline(cin, str); // Läser bort

	}

	string to_string()   //List
	{
		ostringstream oss;

		oss << "(" << Uthyrningsobjekt << ", " << AntalKilowatt << ", " << Yta << ", " << StartMätning << ", " << SlutMätning << ")";

		return oss.str();
	}


	//EnergyConsumption()
	//{
	//}

	~EnergyConsumption()
	{
	}
};

