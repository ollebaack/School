#pragma once
class Wine
{
private:
	string sort, brand, region, supplier;
	int year, bottles, volume;     //volume(mm)
	double price;



public:

	//friend ostream& operator<<(ostream& out, const Article& article)
	//{
	//	out << "(" << article.number << ", " << article.name << ", " << article.price << ")";
	//	return out;
	//}
	//friend istream& operator >> (istream& in, Article& article)
	//{

	//	string s, j;
	//	getline(in, s, '(');
	//	//in >> skipws;
	//	in >> article.number;
	//	getline(in, s, ',');
	//	in >> skipws;
	//	getline(in, article.name, ',');
	//	in >> skipws >> article.price;
	//	getline(in, j, ')');
	//	return in;

	//}

	Wine(int year = 0, string sort = "", string brand = "", double price = 0, int bottles = 0, int volume = 0, string region = 0, string supplier = "")            //id normalt positivt tal.
	{
		this->year = year;
		this->sort = sort;
		this->brand = brand;
		this->price = price;
		this->bottles = bottles;
		this->volume = volume;
		this->region = region;
		this->supplier = supplier;

	}

	int getyear() { return year; }
	void setprice(double price) { this->price = price; }
	string getsort() { return sort; }
	double getprice() { return price; }
	string getbrand() { return brand; }
	string getregion() { return region; }
	string getsupplier() { return supplier; }
	int getvolume() { return volume; }
	int getbottles() { return bottles; }


	//void Write()
	//{
	//	cout << "Number= " << number << endl;

	//	cout << "Name= " << name << endl;

	//	cout << "Price= " << price << endl;
	//}

	//void Read()
	//{
	//	string str;
	//	cout << "Number: ";
	//	cin >> number;
	//	getline(cin, str); // Läser bort
	//	cout << "Name: ";
	//	cin >> name; // (Enter) = '\n' ligger kvar i tecken
	//	getline(cin, str); // Läser bort
	//	cout << "Price: ";
	//	cin >> price;
	//	getline(cin, str);

	//}

	Wine()
	{
	}

	~Wine()
	{
	}
};

