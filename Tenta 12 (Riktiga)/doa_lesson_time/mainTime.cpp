#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <thread>
using namespace std;

#include "Watch.h"
#include "Console.h"
using namespace Course;
#include <Windows.h>


//=============================================================================
//===Funktioner/algoritmer att mät tid på======================================
//=============================================================================

array<int, 10000> as;
array<int, 1000> bs;
default_random_engine dre;
uniform_int_distribution<int> uid1(0, 1000000);

template<size_t SIZE>
void fill_array(array<int, SIZE> &a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = uid1(dre);
	}
}
const int N = 1000;


int min_r(array<int, N> &a, int start)
{

	if (start == a.size() - 1)
	{
		return a[start];
	}
	double smal = min_r(a, start + 1);
	if (a[start] < smal) {
		return a[start];
	}
	else
		return smal;
}
int min_i(array<int, N> &a)
{
	int min = a[0];   // 5 8 2 0 1
	for (int i = a.size() - 1; i > 0; i--)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}


//=============================================================================
//===Hjälpfunktioner för tidmätning============================================
//=============================================================================
void setProcessAndThreadPriority()
{
	if (SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS) == 0)
	{
		std::cout << "Error: SetPriorityClass: " << GetLastError() << endl;
	}
	if (SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL) == 0)
	{
		std::cout << "Error: SetThreadPriority" << endl;
	}
}


//=============================================================================
//=== Kör programmet både i DEBUG- respektive RELEASE-mod
//=== 1. Vilken blir tidskillnanden?
//=== KODOPTIMERING avstängd m.a.p. på en volatil variabel/objekt
//=== 1. För att stänga av kodoptimering använd dig av nyckelordet volatile.
//=============================================================================
void measure(int nLoop)
{
	setProcessAndThreadPriority();

	Course::Watch  w;
	Course::microseconds t0, t1;
	
	//---Tid i tom loop--------------------------------------------------------
	w.restart();
	for (volatile int i = 0; i < nLoop; i++)
	{
		;
	}
	t0 = w.elapsedUs();

	//----Tid för nLoop anrop av alogoritmen-----------------------------------
	w.restart();
	for (volatile int i = 0; i < nLoop; i++)
	{
		//===Algoritm att mäta tid på==================================
		//volatile long r = min_r(bs,0);
		volatile long r = min_i(bs);
		
	}
	t1 = w.elapsedUs();

	//---Utskrift av ungefärlig tid för ETT anrop av alogoritmen---------------
	double time = ((t1 - t0).count() / double(nLoop)); //Mikrosekunder

	std::cout.precision(8);
	std::cout.setf(ios::fixed);
	//std::cout << "Exekveringstid för algoritmen: " << setw(10) << time << " mikrosekunder (nLoop=" << setw(10) << nLoop << ")" << endl;
	std::cout << "Exekveringstid för algoritmen: " << setw(10) << (time*1000) << " nanosekunder (nLoop=" << setw(10) << nLoop << ")" << endl;
}

int main()
{
	int delta = 1000000;
	int nLoopMax = 10000000;
	for (int i = 0; i < nLoopMax; i=i+delta)
	{
		measure(i);
	}
	system("pause");
	return 0;
}