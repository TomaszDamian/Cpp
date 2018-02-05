// foll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int GetToBillion(float State, float Growth) {
	int counter = 0;

	while (State < 1000000000)
	{
		counter++;
		State = State * Growth;
	};

	return counter;
};

int GetBillion()
{
	float growthPercentage;
	float CurrentbankState;
	int howManyYears;
	cout << "Input your current bank state: ";
	cin >> CurrentbankState;
	cout << "what is the growth rate?: ";
	cin >> growthPercentage;

	growthPercentage = (growthPercentage / 100) + 1;

	howManyYears = GetToBillion(CurrentbankState, growthPercentage);

	cout << "it will take you " << howManyYears << " years to get to a Billion" << endl;
	return 0;
};



