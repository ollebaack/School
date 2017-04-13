#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Multimedia.h"

using namespace std;
class Register
{
protected:
	vector<Multimedia> v;
public:
	
	void add();
	void delete_multi();
	void search();
	void List();
	void WriteFile();
	void ReadFromFile();
	void sort();
	Register();
	~Register();
};

