#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include "Statistics.h"
#include"Nils.h"
using namespace Tent;
using namespace Tentt;



float rek(int n)
{
		float n1 = 0;
		
		if (n <= 1)
			return 1;
	
		else
			n1 = 1/sqrt(n) + rek(n - 1);
		
		return n1;


}

float ite(int n)
{
	float n1 = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i != 0)
			n1 += 1 / sqrt(i);

	}
	return n1;
}





int main()
{
	//cout << rek(3) << endl; // borde bli 2,28  RÄTTT
	//cout << ite(3);

	//Statistics stat;
	//stat.Readfromfile();
	//stat.list();
	//cout << "Meanvalue: " << stat.calculate_mean() << endl;


	Nils nh;

	nh.Readfromfile();
	cout << "Ord med max frekvens: " << nh.maxFrequency() << endl;
	cout << "Totala antalet ord: " << nh.totalNumbersOfWords() << endl;

	nh.map2pq();
	nh.printAndPopPriorityQueue(20);


	system("pause");
	return 0;
}